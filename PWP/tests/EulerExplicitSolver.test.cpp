#include "pvi/EulerExplicitSolver.hpp"
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

TEST_CASE("EulerExplicitSolver") {
    const double tolerance = 1e-4;
    EulerExplicitSolver solver;

    SUBCASE("PVI-1: bate com os valores calculados manualmente na Aula 24") {
        auto states = solver.solve(pvi1, {2.0}, 0.0, 0.5, 2);
        CHECK(states[1][0] == doctest::Approx(8.0 / 3.0).epsilon(tolerance));
        CHECK(states[2][0] == doctest::Approx(32.0 / 9.0).epsilon(tolerance));
    }

    SUBCASE("PVI-2: primeiro passo bate com a Aula 24") {
        auto F = makePvi2(10.0, 0.5, 0.5);
        auto states = solver.solve(F, {3.0, 150.0}, 0.0, 0.1, 1);
        CHECK(states[1][0] == doctest::Approx(1.7).epsilon(tolerance));
        CHECK(states[1][1] == doctest::Approx(150.3).epsilon(tolerance));
    }
}