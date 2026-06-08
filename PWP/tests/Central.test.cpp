#include "derivate/Derivate.hpp"
#include "derivate/DerivateBase.hpp"
#include "doctest.h"

using namespace PWP::lib::numeric_methods::derivate;

namespace {
auto linear(double xValue) -> double { return (3.0 * xValue) + 2.0; }
auto quadratic(double xValue) -> double { return xValue * xValue; }
auto cubic(double xValue) -> double { return xValue * xValue * xValue; }
auto quartic(double xValue) -> double { return xValue * xValue * xValue * xValue; }
} // namespace

TEST_CASE("Central O(h^2)") {
    const double xValue = 1.234;
    const double hValue = 1e-5;
    const double hValue_d3 = 1e-3;
    const double hValue_d4 = 1e-2;

    SUBCASE("1a derivada") {
        Derivate central(MethodType::Central, DerivativeOrder::First, ErrorOrder::O_h2);
        CHECK(central.calculate(linear, xValue, hValue) == doctest::Approx(3.0).epsilon(hValue));
    }
}