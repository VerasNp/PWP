#include "Forward.hpp"
#include "DerivateBase.hpp"
#include "ForwardCreator.hpp"
#include "IDerivate.hpp"
#include "doctest.h"

using namespace PWP::lib::numeric_methods::derivate;

namespace {
auto linear(double xValue) -> double { return (3.0 * xValue) + 2.0; }

auto d1_linear() -> double { return 3.0; }

} // namespace

TEST_CASE("Forward") {
    SUBCASE("") {
        std::unique_ptr<IDerivate> forward =
            ForwardCreator().create(DerivativeOrder::First, ErrorOrder::O_h);
        const double xValue = 1.234;
        const double hValue = 1e-5;
        double result = forward->calculate(linear, xValue, hValue);
    }
}