#pragma once

#include "DerivateBase.hpp"
namespace PWP::lib::numeric_methods::derivate {
class Derivate {
  public:
    Derivate(MethodType methodType, DerivativeOrder derivateOrder, ErrorOrder errorOrder);
    auto calculate(double (*func)(double), double xValue, double hValue) const -> double;

  private:
    MethodType methodType_;
    ErrorOrder errorOrder_;
    DerivativeOrder derivateOrder_;
};
} // namespace PWP::lib::numeric_methods::derivate