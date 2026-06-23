#include "integrate/ExponentialChange.hpp"
#include "integrate/gauss/GaussLegendre.hpp"
#include "integrate/NewtonCotes.hpp"
#include "doctest.h"
#include <cmath>

using namespace PWP::lib::numeric_methods::integrate;
using namespace PWP::lib::numeric_methods::integrate::ExponentialChange;
using namespace PWP::lib::numeric_methods::integrate::GaussLegendre;
using namespace PWP::lib::numeric_methods::integrate::NewtonCotes;

// ─── simpleExp ───────────────────────────────────────────────────────────────
// Substituição x(t) = (a+b)/2 + (b-a)/2·tanh(t).
// Erro de truncamento ~ (1 - tanh(c)) para funções suaves.
// Com c=6 (padrão): truncamento ≈ 1.2e-7 — adequado para tol=1e-6.

TEST_CASE("simpleExp — funções suaves: ∫₀¹ x² dx = 1/3") {
    auto f = [](double x) -> double { return x * x; };

    SUBCASE("GL3") {
        CHECK(simpleExp(f, 0.0, 1.0, GL3) ==
              doctest::Approx(1.0 / 3.0).epsilon(1e-6));
    }
    SUBCASE("GL4") {
        CHECK(simpleExp(f, 0.0, 1.0, GL4) ==
              doctest::Approx(1.0 / 3.0).epsilon(1e-6));
    }
    SUBCASE("NC Closed Degree3") {
        CHECK(simpleExp(f, 0.0, 1.0, Closed::Degree3) ==
              doctest::Approx(1.0 / 3.0).epsilon(1e-6));
    }
}

TEST_CASE("simpleExp — funções suaves: ∫₀¹ eˣ dx = e - 1") {
    auto f = [](double x) -> double { return std::exp(x); };

    SUBCASE("GL3") {
        CHECK(simpleExp(f, 0.0, 1.0, GL3) ==
              doctest::Approx(std::exp(1.0) - 1.0).epsilon(1e-6));
    }
    SUBCASE("GL4") {
        CHECK(simpleExp(f, 0.0, 1.0, GL4) ==
              doctest::Approx(std::exp(1.0) - 1.0).epsilon(1e-6));
    }
}

// simpleExp com 1/√x: requer c grande pois truncamento ~ √(1-tanh(c)).
// c=14 → truncamento ≈ 1.65e-6, dentro de tol=1e-4.
TEST_CASE("simpleExp — singularidade fraca: ∫₀¹ 1/√x dx = 2 (c=14)") {
    auto f = [](double x) -> double { return 1.0 / std::sqrt(x); };

    SUBCASE("GL4") {
        CHECK(simpleExp(f, 0.0, 1.0, GL4, 14.0) ==
              doctest::Approx(2.0).epsilon(1e-4));
    }
    SUBCASE("NC Closed Degree3") {
        CHECK(simpleExp(f, 0.0, 1.0, Closed::Degree3, 14.0) ==
              doctest::Approx(2.0).epsilon(1e-4));
    }
}

// ─── doubleExp ───────────────────────────────────────────────────────────────
// Substituição tanh-sinh: decay duplo exponencial em ±c.
// Truncamento ~ exp(-exp(c)) — excelente para singularidades nos endpoints.

TEST_CASE("doubleExp — singularidade unilateral: ∫₀¹ 1/√x dx = 2") {
    auto f = [](double x) -> double { return 1.0 / std::sqrt(x); };

    SUBCASE("GL3") {
        CHECK(doubleExp(f, 0.0, 1.0, GL3) ==
              doctest::Approx(2.0).epsilon(1e-5));
    }
    SUBCASE("GL4") {
        CHECK(doubleExp(f, 0.0, 1.0, GL4) ==
              doctest::Approx(2.0).epsilon(1e-5));
    }
    SUBCASE("NC Closed Degree3") {
        CHECK(doubleExp(f, 0.0, 1.0, Closed::Degree3) ==
              doctest::Approx(2.0).epsilon(1e-5));
    }
}

TEST_CASE("doubleExp — singularidade bilateral: ∫₋₁¹ 1/√(1-x²) dx = π") {
    auto f = [](double x) -> double { return 1.0 / std::sqrt(1.0 - x * x); };

    SUBCASE("GL3") {
        CHECK(doubleExp(f, -1.0, 1.0, GL3) ==
              doctest::Approx(M_PI).epsilon(1e-5));
    }
    SUBCASE("GL4") {
        CHECK(doubleExp(f, -1.0, 1.0, GL4) ==
              doctest::Approx(M_PI).epsilon(1e-5));
    }
}

TEST_CASE("doubleExp — singularidade bilateral em [0,1]: ∫₀¹ 1/√(x(1-x)) dx = π") {
    auto f = [](double x) -> double { return 1.0 / std::sqrt(x * (1.0 - x)); };

    SUBCASE("GL3") {
        CHECK(doubleExp(f, 0.0, 1.0, GL3) ==
              doctest::Approx(M_PI).epsilon(1e-5));
    }
    SUBCASE("GL4") {
        CHECK(doubleExp(f, 0.0, 1.0, GL4) ==
              doctest::Approx(M_PI).epsilon(1e-5));
    }
}

TEST_CASE("doubleExp — singularidade logarítmica: ∫₀¹ ln(x) dx = -1") {
    auto f = [](double x) -> double { return std::log(x); };

    SUBCASE("GL3") {
        CHECK(doubleExp(f, 0.0, 1.0, GL3) ==
              doctest::Approx(-1.0).epsilon(1e-5));
    }
    SUBCASE("GL4") {
        CHECK(doubleExp(f, 0.0, 1.0, GL4) ==
              doctest::Approx(-1.0).epsilon(1e-5));
    }
}

TEST_CASE("doubleExp — função regular: ∫₀¹ x² dx = 1/3") {
    auto f = [](double x) -> double { return x * x; };
    CHECK(doubleExp(f, 0.0, 1.0, GL3) ==
          doctest::Approx(1.0 / 3.0).epsilon(1e-6));
}
