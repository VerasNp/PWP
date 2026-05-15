#pragma once

#include "DerivateBase.hpp"
#include "IDerivate.hpp"

namespace PWP::lib::numeric_methods::derivate {
class Forward : public IDerivate {
  public:
    Forward(DerivativeOrder derivateOrder, ErrorOrder errorOrder);
    auto calculate(double (*func)(double), double xValue, double hValue) const -> double override;
    // auto First(double (*func)(double), double xValue, double hValue) const -> double override;
    // auto Second(double (*func)(double), double xValue, double hValue) const -> double override;
    // auto Third(double (*func)(double), double xValue, double hValue) const -> double override;
    // auto Fourth(double (*func)(double), double xValue, double hValue) const -> double override;
    ErrorOrder errorOrder;
    DerivativeOrder derivateOrder;
};
} // namespace PWP::lib::numeric_methods::derivate