#include "pvi/EulerImplicitSolver.hpp"
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

TEST_CASE("EulerImplicitSolver") {
    const double tolerance = 1e-4;
    EulerImplicitSolver solver;

    SUBCASE("PVI-1: bate com os valores calculados manualmente na Aula 24") {
        auto states = solver.solve(pvi1, {2.0}, 0.0, 0.5, 2);
        CHECK(states[1][0] == doctest::Approx(3.0).epsilon(tolerance));
        CHECK(states[2][0] == doctest::Approx(4.5).epsilon(tolerance));
    }

    SUBCASE("PVI-2: primeiro passo bate com a Aula 24") {
        auto F = makePvi2(10.0, 0.5, 0.5);
        auto states = solver.solve(F, {3.0, 150.0}, 0.0, 0.1, 1);
        CHECK(states[1][0] == doctest::Approx(1.81818).epsilon(tolerance));
        CHECK(states[1][1] == doctest::Approx(150.18182).epsilon(tolerance));
    }

    SUBCASE("construtor aceita tolerância e máximo de iterações customizados") {
        EulerImplicitSolver looseSolver(1e-3, 10);
        auto states = looseSolver.solve(pvi1, {2.0}, 0.0, 0.5, 1);
        CHECK(states[1][0] == doctest::Approx(3.0).epsilon(1e-2));
    }
}