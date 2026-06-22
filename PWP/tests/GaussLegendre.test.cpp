#include "integrate/Integrate.hpp"
#include "integrate/GaussLegendre.hpp"
#include "doctest.h"
#include <cmath>

using namespace PWP::lib::numeric_methods::integrate;
using namespace PWP::lib::numeric_methods::integrate::GaussLegendre;

namespace {
auto testFunc(double x) -> double {
    double v = std::sin(2 * x) + 4 * x * x + 3 * x;
    return v * v;
}
const double EXACT = 17.8764703;
} // namespace

TEST_CASE("applyQuadrature N=1 — exatidão polinomial") {
    SUBCASE("GL2 integra x³ exatamente em [0,1]") {
        auto f = [](double x) -> double { return x * x * x; };
        CHECK(applyQuadrature(GL2, +f, 0.0, 1.0) ==
              doctest::Approx(0.25).epsilon(1e-14));
    }
    SUBCASE("GL3 integra x⁵ exatamente em [0,1]") {
        auto f = [](double x) -> double { return x*x*x*x*x; };
        CHECK(applyQuadrature(GL3, +f, 0.0, 1.0) ==
              doctest::Approx(1.0/6.0).epsilon(1e-14));
    }
    SUBCASE("GL4 integra x⁷ exatamente em [0,1]") {
        auto f = [](double x) -> double { return x*x*x*x*x*x*x; };
        CHECK(applyQuadrature(GL4, +f, 0.0, 1.0) ==
              doctest::Approx(0.125).epsilon(1e-14));
    }
}

TEST_CASE("integrate adaptativo — Gauss-Legendre") {
    const double tol = 1e-6;
    SUBCASE("GL2") {
        CHECK(integrate(GL2, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("GL3") {
        CHECK(integrate(GL3, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
    SUBCASE("GL4") {
        CHECK(integrate(GL4, testFunc, 0, 1, tol) ==
              doctest::Approx(EXACT).epsilon(tol * 10));
    }
}
