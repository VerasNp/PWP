#include "IDerivate.hpp"

namespace PWP::lib::numeric_methods::derivate {
class Central : public IDerivate {
    // double First(double (*func)(double), const double x,
    //              const double h) const override;
    // double Second(double (*func)(double), const double x,
    //               const double h) const override;
    // double Third(double (*func)(double), const double x,
    //              const double h) const override;
    // double Fourth(double (*func)(double), const double x,
    //               const double h) const override;

  public:
    auto calculate(double (*func)(double), double xValue, double hValue) const -> double override;
};
} // namespace PWP::lib::numeric_methods::derivate