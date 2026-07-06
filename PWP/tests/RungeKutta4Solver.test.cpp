#include "pvi/RungeKutta4Solver.hpp"
#include <cmath>
#include <doctest.h>

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

TEST_CASE("RungeKutta4Solver") {
    RungeKutta4Solver solver;

    SUBCASE("PVI-1: erro diminui conforme Δt diminui (ordem de convergência)") {
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

    SUBCASE("PVI-1: erro é muito pequeno mesmo com Δt moderado (ordem 4)") {
        const double t0 = 0.0, tf = 10.0, dt = 0.1;
        int steps = static_cast<int>((tf - t0) / dt);
        auto states = solver.solve(pvi1, {2.0}, t0, dt, steps);
        double error = std::abs(states.back()[0] - pvi1Exact(tf)) / pvi1Exact(tf);
        CHECK(error < 1e-5);
    }

    SUBCASE("PVI-2: primeiro passo bate com a solução exata") {
        const double g = 10.0, k = 0.5, m = 0.5, v0 = 3.0, y0 = 150.0;
        auto F = makePvi2(g, k, m);
        auto states = solver.solve(F, {v0, y0}, 0.0, 0.1, 1);
        auto exact = pvi2Exact(0.1, v0, y0, g, k, m);

        CHECK(states[1][0] == doctest::Approx(exact[0]).epsilon(1e-4));
        CHECK(states[1][1] == doctest::Approx(exact[1]).epsilon(1e-4));
    }

    SUBCASE("PVI-2: previsão da queda no mar bate com a Aula 25") {
        const double g = 10.0, k = 0.5, m = 0.5, v0 = 3.0, y0 = 150.0;
        auto F = makePvi2(g, k, m);
        auto states = solver.solve(F, {v0, y0}, 0.0, 0.1, 163);

        CHECK(states.back()[0] == doctest::Approx(-10.0).epsilon(1e-2));
        CHECK(states.back()[1] == doctest::Approx(0.0).epsilon(1e-1));
    }
}