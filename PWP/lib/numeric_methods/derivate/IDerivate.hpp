#pragma once

namespace PWP::lib::numeric_methods::derivate {
class IDerivate {
  public:
    virtual ~IDerivate();
    virtual auto calculate(double (*func)(double), double xValue, double hValue) const
        -> double = 0;
    // virtual auto First(double (*func)(double), double xValue, double hValue) const -> double = 0;
    // virtual auto Second(double (*func)(double), double xValue, double hValue) const -> double =
    // 0; virtual auto Third(double (*func)(double), double xValue, double hValue) const -> double =
    // 0; virtual auto Fourth(double (*func)(double), double xValue, double hValue) const -> double
    // = 0;
};
} // namespace PWP::lib::numeric_methods::derivate