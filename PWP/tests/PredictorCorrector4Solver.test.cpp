#include "pvi/PredictorCorrector4Solver.hpp"
#include <cmath>
#include <doctest.h>
#include <stdexcept>

using namespace PWP::lib::numeric_methods::pvi;

inline const ODEFunction pvi1 = [](const State &S, double /*t*/) -> State {
    return {(2.0 / 3.0) * S[0]};
};

inline auto pvi1Exact(double t) -> double { return 2.0 * std::exp((2.0 / 3.0) * t); }

inline auto makePvi2(double g, double k, double m) -> ODEFunction {
    return [g, k, m](const State &S, double /*t*/) -> State {
        double v = S[0];
        return {-g - (k / m) * v, v};
    };
}

inline auto pvi2Exact(double t, double v0, double y0, double g, double k, double m) -> State {
    double km = k / m;
    double v = -g / km + (v0 + g / km) * std::exp(-km * t);
    double y = y0 - (g / km) * t - (v0 + g / km) * (1.0 / km) * (std::exp(-km * t) - 1.0);
    return {v, y};
}

TEST_CASE("PredictorCorrector4Solver") {
    PredictorCorrector4Solver solver;

    SUBCASE("PVI-1: erro diminui conforme Δt diminui") {
        const double t0 = 0.0, tf = 10.0;
        const double exact = pvi1Exact(tf);

        double previousError = 1e9;
        for (double dt : {0.1, 0.01, 0.001}) {
            int steps = static_cast<int>((tf - t0) / dt);
            auto states = solver.solve(pvi1, {2.0}, t0, dt, steps);
            double error = std::abs(states.back()[0] - exact) / exact;
            CHECK(error < previousError);
            previousError = error;
        }
    }

    SUBCASE("PVI-2: resultado após alguns passos é próximo da solução exata") {
        const double g = 10.0, k = 0.5, m = 0.5, v0 = 3.0, y0 = 150.0;
        auto F = makePvi2(g, k, m);
        double dt = 0.1;
        int steps = 20;

        auto states = solver.solve(F, {v0, y0}, 0.0, dt, steps);
        auto exact = pvi2Exact(steps * dt, v0, y0, g, k, m);

        CHECK(states.back()[0] == doctest::Approx(exact[0]).epsilon(1e-3));
        CHECK(states.back()[1] == doctest::Approx(exact[1]).epsilon(1e-3));
    }

    SUBCASE("lança exceção se steps for insuficiente para a fase de inicialização") {
        auto callWithInsufficientSteps = [&]() {
            auto result = solver.solve(pvi1, {2.0}, 0.0, 0.5, 2);
        };
        CHECK_THROWS_AS(callWithInsufficientSteps(), std::invalid_argument);
    }

    SUBCASE("construtor aceita tolerância e máximo de iterações customizados") {
        PredictorCorrector4Solver looseSolver(1e-3, 5);
        auto states = looseSolver.solve(pvi1, {2.0}, 0.0, 0.1, 10);
        CHECK(states.size() == 11);
    }
}