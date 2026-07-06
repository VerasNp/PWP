#include "integrate/gauss/GaussLaguerre.hpp"
#include "doctest.h"
#include <cmath>

using namespace PWP::lib::numeric_methods::integrate;
using namespace PWP::lib::numeric_methods::integrate::GaussLaguerre;

TEST_CASE("GL2 — exact for degree ≤ 3") {
    SUBCASE("∫ e^{-x} dx = 1") {
        CHECK(applyRule(GL2, [](double) { return 1.0; }) ==
              doctest::Approx(1.0).epsilon(1e-14));
    }
    SUBCASE("∫ e^{-x} x dx = 1") {
        CHECK(applyRule(GL2, [](double x) { return x; }) ==
              doctest::Approx(1.0).epsilon(1e-14));
    }
    SUBCASE("∫ e^{-x} x² dx = 2") {
        CHECK(applyRule(GL2, [](double x) { return x*x; }) ==
              doctest::Approx(2.0).epsilon(1e-14));
    }
    SUBCASE("∫ e^{-x} x³ dx = 6") {
        CHECK(applyRule(GL2, [](double x) { return x*x*x; }) ==
              doctest::Approx(6.0).epsilon(1e-14));
    }
}

TEST_CASE("GL3 — exact for degree ≤ 5") {
    SUBCASE("∫ e^{-x} x⁴ dx = 24") {
        auto f = [](double x) { return x*x*x*x; };
        CHECK(applyRule(GL3, f) == doctest::Approx(24.0).epsilon(1e-12));
    }
    SUBCASE("∫ e^{-x} x⁵ dx = 120") {
        auto f = [](double x) { return x*x*x*x*x; };
        CHECK(applyRule(GL3, f) == doctest::Approx(120.0).epsilon(1e-11));
    }
}

TEST_CASE("GL4 — exact for degree ≤ 7") {
    SUBCASE("∫ e^{-x} x⁶ dx = 720") {
        auto f = [](double x) { return x*x*x*x*x*x; };
        CHECK(applyRule(GL4, f) == doctest::Approx(720.0).epsilon(1e-10));
    }
    SUBCASE("∫ e^{-x} x⁷ dx = 5040") {
        auto f = [](double x) { return x*x*x*x*x*x*x; };
        CHECK(applyRule(GL4, f) == doctest::Approx(5040.0).epsilon(1e-9));
    }
}
