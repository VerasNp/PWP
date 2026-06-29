#include "integrate/gauss/GaussChebyshev.hpp"
#include "doctest.h"
#include <cmath>

using namespace PWP::lib::numeric_methods::integrate;
using namespace PWP::lib::numeric_methods::integrate::GaussChebyshev;

TEST_CASE("T1::GC2 — exact for degree ≤ 3") {
    SUBCASE("∫ 1/√(1-x²) dx = π") {
        CHECK(applyRule(T1::GC2, [](double) { return 1.0; }) ==
              doctest::Approx(M_PI).epsilon(1e-14));
    }
    SUBCASE("∫ x²/√(1-x²) dx = π/2") {
        CHECK(applyRule(T1::GC2, [](double x) { return x*x; }) ==
              doctest::Approx(M_PI/2.0).epsilon(1e-14));
    }
    SUBCASE("∫ x³/√(1-x²) dx = 0  (odd)") {
        CHECK(applyRule(T1::GC2, [](double x) { return x*x*x; }) ==
              doctest::Approx(0.0).epsilon(1e-14));
    }
}

TEST_CASE("T1::GC3 — exact for degree ≤ 5") {
    SUBCASE("∫ x⁴/√(1-x²) dx = 3π/8") {
        auto f = [](double x) { return x*x*x*x; };
        CHECK(applyRule(T1::GC3, f) ==
              doctest::Approx(3.0*M_PI/8.0).epsilon(1e-14));
    }
}

TEST_CASE("T1::GC4 — exact for degree ≤ 7") {
    SUBCASE("∫ x⁶/√(1-x²) dx = 5π/16") {
        auto f = [](double x) { return x*x*x*x*x*x; };
        CHECK(applyRule(T1::GC4, f) ==
              doctest::Approx(5.0*M_PI/16.0).epsilon(1e-14));
    }
}

TEST_CASE("T2::GC2 — exact for degree ≤ 3") {
    SUBCASE("∫ √(1-x²) dx = π/2") {
        CHECK(applyRule(T2::GC2, [](double) { return 1.0; }) ==
              doctest::Approx(M_PI/2.0).epsilon(1e-14));
    }
    SUBCASE("∫ x²·√(1-x²) dx = π/8") {
        CHECK(applyRule(T2::GC2, [](double x) { return x*x; }) ==
              doctest::Approx(M_PI/8.0).epsilon(1e-14));
    }
    SUBCASE("∫ x³·√(1-x²) dx = 0  (odd)") {
        CHECK(applyRule(T2::GC2, [](double x) { return x*x*x; }) ==
              doctest::Approx(0.0).epsilon(1e-14));
    }
}

TEST_CASE("T2::GC3 — exact for degree ≤ 5") {
    SUBCASE("∫ x⁴·√(1-x²) dx = π/16") {
        auto f = [](double x) { return x*x*x*x; };
        CHECK(applyRule(T2::GC3, f) ==
              doctest::Approx(M_PI/16.0).epsilon(1e-14));
    }
}

TEST_CASE("T2::GC4 — exact for degree ≤ 7") {
    SUBCASE("∫ x⁶·√(1-x²) dx = 5π/128") {
        auto f = [](double x) { return x*x*x*x*x*x; };
        CHECK(applyRule(T2::GC4, f) ==
              doctest::Approx(5.0*M_PI/128.0).epsilon(1e-14));
    }
}
