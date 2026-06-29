#include "integrate/gauss/GaussHermite.hpp"
#include "doctest.h"
#include <cmath>

using namespace PWP::lib::numeric_methods::integrate;
using namespace PWP::lib::numeric_methods::integrate::GaussHermite;

TEST_CASE("GH2 — exact for degree ≤ 3") {
    SUBCASE("∫ e^{-x²} dx = √π") {
        CHECK(applyRule(GH2, [](double) { return 1.0; }) ==
              doctest::Approx(std::sqrt(M_PI)).epsilon(1e-14));
    }
    SUBCASE("∫ e^{-x²} x² dx = √π/2") {
        CHECK(applyRule(GH2, [](double x) { return x*x; }) ==
              doctest::Approx(std::sqrt(M_PI)/2.0).epsilon(1e-14));
    }
    SUBCASE("∫ e^{-x²} x³ dx = 0  (odd)") {
        CHECK(applyRule(GH2, [](double x) { return x*x*x; }) ==
              doctest::Approx(0.0).epsilon(1e-14));
    }
}

TEST_CASE("GH3 — exact for degree ≤ 5") {
    SUBCASE("∫ e^{-x²} x⁴ dx = 3√π/4") {
        CHECK(applyRule(GH3, [](double x) { return x*x*x*x; }) ==
              doctest::Approx(3.0*std::sqrt(M_PI)/4.0).epsilon(1e-14));
    }
    SUBCASE("∫ e^{-x²} x⁵ dx = 0  (odd)") {
        CHECK(applyRule(GH3, [](double x) { return x*x*x*x*x; }) ==
              doctest::Approx(0.0).epsilon(1e-14));
    }
}

TEST_CASE("GH4 — exact for degree ≤ 7") {
    SUBCASE("∫ e^{-x²} x⁶ dx = 15√π/8") {
        auto f = [](double x) { return x*x*x*x*x*x; };
        CHECK(applyRule(GH4, f) ==
              doctest::Approx(15.0*std::sqrt(M_PI)/8.0).epsilon(1e-13));
    }
    SUBCASE("∫ e^{-x²} x⁷ dx = 0  (odd)") {
        auto f = [](double x) { return x*x*x*x*x*x*x; };
        CHECK(applyRule(GH4, f) ==
              doctest::Approx(0.0).epsilon(1e-13));
    }
}
