#include "derivate/stencil/backward/BackwardStencil.hpp"
#include "derivate/stencil/Stencil.hpp"
#include "derivate/DerivateBase.hpp"
#include "doctest.h"
#include <cstdlib>

using namespace PWP::lib::numeric_methods::derivate;
using namespace PWP::lib::numeric_methods::derivate::stencil;
using namespace PWP::lib::numeric_methods::derivate::stencil::backward;

namespace {
auto linear(double x)    -> double { return (3.0 * x) + 2.0; }
auto quadratic(double x) -> double { return x * x; }
auto cubic(double x)     -> double { return x * x * x; }
auto quartic(double x)   -> double { return x * x * x * x; }
} // namespace

TEST_CASE("Backward O(h)") {
    const double xValue = 1.234;
    const double hValue     = 1e-5;
    const double hValue_d3  = 1e-3;
    const double hValue_d4  = 1e-2;

    SUBCASE("1a derivada") {
        CHECK(apply(firstBackward2Points, linear, xValue, hValue) ==
              doctest::Approx(3.0).epsilon(hValue));
    }

    SUBCASE("2a derivada") {
        CHECK(apply(secondBackward3Points, quadratic, xValue, hValue) ==
              doctest::Approx(2.0).epsilon(hValue));
    }

    SUBCASE("3a derivada") {
        CHECK(apply(thirdBackward4Points, cubic, xValue, hValue_d3) ==
              doctest::Approx(6.0).epsilon(hValue_d3));
    }

    SUBCASE("4a derivada") {
        CHECK(apply(fourthBackward5Points, quartic, xValue, hValue_d4) ==
              doctest::Approx(24.0).epsilon(hValue_d4));
    }
}

TEST_CASE("Backward O(h2)") {
    const double xValue      = 1.234;
    const double hValue      = 1e-3;
    const double hValue_d3   = 1e-2;
    const double hValue_d4   = 1e-2;

    SUBCASE("1a derivada") {
        CHECK(apply(firstBackward3Points, linear, xValue, hValue) ==
              doctest::Approx(3.0).epsilon(hValue * hValue));
    }

    SUBCASE("2a derivada") {
        CHECK(apply(secondBackward4Points, quadratic, xValue, hValue) ==
              doctest::Approx(2.0).epsilon(hValue * hValue));
    }

    SUBCASE("3a derivada") {
        CHECK(apply(thirdBackward5Points, cubic, xValue, hValue_d3) ==
              doctest::Approx(6.0).epsilon(hValue_d3));
    }

    SUBCASE("4a derivada") {
        CHECK(apply(fourthBackward6Points, quartic, xValue, hValue_d4) ==
              doctest::Approx(24.0).epsilon(hValue_d4));
    }
}

TEST_CASE("Backward O(h2) mais preciso que O(h)") {
    const double xValue = 1.234;
    const double hValue = 1e-3;

    const double exact    = 2.0 * xValue;
    const double erro_oh  = std::abs(apply(firstBackward2Points, quadratic, xValue, hValue) - exact);
    const double erro_oh2 = std::abs(apply(firstBackward3Points, quadratic, xValue, hValue) - exact);

    CHECK(erro_oh2 < erro_oh);
}
