#include "integrate/Integrate.hpp"
#include "integrate/NewtonCotes.hpp"
#include "doctest.h"
#include <cmath>

using namespace PWP::lib::numeric_methods::integrate;
using namespace PWP::lib::numeric_methods::integrate::NewtonCotes;

namespace {
// f(x) = (sin(2x) + 4x² + 3x)²   integral exata em [0,1] ≈ 17.8764703
auto testFunc(double x) -> double {
    double v = std::sin(2 * x) + 4 * x * x + 3 * x;
    return v * v;
}
const double EXACT = 17.8764703;
} // namespace

// ── applyQuadrature (N=1) ────────────────────────────────────────────────────

TEST_CASE("applyQuadrature N=1 — fechadas") {
    SUBCASE("grau 1 (Trapézio)") {
        CHECK(applyQuadrature(Closed::Degree1, testFunc, 0, 1) ==
              doctest::Approx(31.28).epsilon(0.01));
    }
    SUBCASE("grau 2 (Simpson 1/3)") {
        CHECK(applyQuadrature(Closed::Degree2, testFunc, 0, 1) ==
              doctest::Approx(17.87).epsilon(0.01));
    }
    SUBCASE("grau 3 (Simpson 3/8)") {
        CHECK(applyQuadrature(Closed::Degree3, testFunc, 0, 1) ==
              doctest::Approx(17.86).epsilon(0.01));
    }
}

TEST_CASE("applyQuadrature N=1 — abertas") {
    SUBCASE("grau 1") {
        CHECK(applyQuadrature(Open::Degree1, testFunc, 0, 1) ==
              doctest::Approx(13.41).epsilon(0.01));
    }
    SUBCASE("grau 2 (Milne)") {
        CHECK(applyQuadrature(Open::Degree2, testFunc, 0, 1) ==
              doctest::Approx(17.89).epsilon(0.01));
    }
    SUBCASE("grau 3") {
        CHECK(applyQuadrature(Open::Degree3, testFunc, 0, 1) ==
              doctest::Approx(17.88).epsilon(0.01));
    }
    SUBCASE("grau 4") {
        CHECK(applyQuadrature(Open::Degree4, testFunc, 0, 1) ==
              doctest::Approx(17.88).epsilon(0.01));
    }
}

// ── integrate com subdivisão adaptativa ──────────────────────────────────────

TEST_CASE("integrate adaptativo — fechadas") {
    const double tol = 1e-6;
    SUBCASE("grau 1") {
        CHECK(integrate(Closed::Degree1, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("grau 2") {
        CHECK(integrate(Closed::Degree2, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("grau 3") {
        CHECK(integrate(Closed::Degree3, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("grau 4 (Boole)") {
        CHECK(integrate(Closed::Degree4, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
}

TEST_CASE("integrate adaptativo — abertas") {
    const double tol = 1e-6;
    SUBCASE("grau 1") {
        CHECK(integrate(Open::Degree1, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("grau 2 (Milne)") {
        CHECK(integrate(Open::Degree2, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("grau 3") {
        CHECK(integrate(Open::Degree3, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("grau 4") {
        CHECK(integrate(Open::Degree4, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
}

// ── sanidade: integrais simples ───────────────────────────────────────────────

TEST_CASE("integrate — constante e polinômio") {
    auto constant = [](double) -> double { return 1.0; };
    auto linear   = [](double x) -> double { return x; };
    auto quadratic = [](double x) -> double { return x * x; };
    const double tol = 1e-6;

    SUBCASE("∫1 dx [0,2] = 2 (fechada grau 1)") {
        CHECK(integrate(Closed::Degree1, +constant, 0, 2, tol) ==
              doctest::Approx(2.0).epsilon(tol));
    }
    SUBCASE("∫x dx [0,1] = 0.5 (fechada grau 2)") {
        CHECK(integrate(Closed::Degree2, +linear, 0, 1, tol) ==
              doctest::Approx(0.5).epsilon(tol));
    }
    SUBCASE("∫x² dx [0,1] = 1/3 (aberta grau 2)") {
        CHECK(integrate(Open::Degree2, +quadratic, 0, 1, tol) ==
              doctest::Approx(1.0 / 3.0).epsilon(tol));
    }
}
