#include "derivate/Derivate.hpp"
#include "derivate/DerivateBase.hpp"
#include "doctest.h"
#include <cstdlib>
#include <iostream>

using namespace PWP::lib::numeric_methods::derivate;

namespace {
auto linear(double xValue) -> double { return (3.0 * xValue) + 2.0; }
auto quadratic(double xValue) -> double { return xValue * xValue; }
auto cubic(double xValue) -> double { return xValue * xValue * xValue; }
auto quartic(double xValue) -> double { return xValue * xValue * xValue * xValue; }
} // namespace

TEST_CASE("Forward O(h)") {
    const double xValue = 1.234;
    const double hValue = 1e-5;
    const double hValue_d3 = 1e-3;
    const double hValue_d4 = 1e-2;

    SUBCASE("1a derivada") {
        Derivate forward(DerivativeOrder::First, ErrorOrder::O_h);
        CHECK(forward.calculate(linear, xValue, hValue) == doctest::Approx(3.0).epsilon(hValue));
    }

    SUBCASE("2a derivada") {
        Derivate forward(DerivativeOrder::Second, ErrorOrder::O_h);
        CHECK(forward.calculate(quadratic, xValue, hValue) ==
        doctest::Approx(2.0).epsilon(hValue));
    }

    SUBCASE("3a derivada") {
        Derivate forward(DerivativeOrder::Third, ErrorOrder::O_h);
        CHECK(forward.calculate(cubic, xValue, hValue_d3) ==
              doctest::Approx(6.0).epsilon(hValue_d3));
    }

    SUBCASE("4a derivada") {
        Derivate forward(DerivativeOrder::Fourth, ErrorOrder::O_h);
        CHECK(forward.calculate(quartic, xValue, hValue_d4) ==
              doctest::Approx(24.0).epsilon(hValue_d4));
    }
}

// TEST_CASE("Forward O(h2)") {
//     const double xValue = 1.234;
//     const double hValue = 1e-3;

//     SUBCASE("1a derivada") {
//         Derivate forward(DerivativeOrder::First, ErrorOrder::O_h2);
//         CHECK(forward.calculate(linear, xValue, hValue) ==
//               doctest::Approx(3.0).epsilon(hValue * hValue));
//     }
// }

// TEST_CASE("Forward O(h2) mais preciso que O(h)") {
//     const double xValue = 1.234;
//     const double hValue = 1e-3;
//     Derivate forwardOh(DerivativeOrder::First, ErrorOrder::O_h);
//     Derivate forwardOh2(DerivativeOrder::First, ErrorOrder::O_h2);
//     const double exact = 2.0 * xValue;
//     const double erro_oh = std::abs(forwardOh.calculate(quadratic, xValue, hValue) - exact);
//     const double erro_oh2 = std::abs(forwardOh2.calculate(quadratic, xValue, hValue) - exact);
//     CHECK(erro_oh2 < erro_oh);
// }