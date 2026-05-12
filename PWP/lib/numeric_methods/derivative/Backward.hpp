// #pragma once

// #include "IDerivate.hpp"
// #include "stencil/Stencil.hpp"

// namespace PWP::lib::numeric_methods::derivate {
// class Backward : public IDerivate {
// public:
//   Backward(ErrorOrder errorOrder);

// public:
//   double First(double (*func)(double), const double x,
//                const double h) const override;
//   double Second(double (*func)(double), const double x,
//                 const double h) const override;
//   double Third(double (*func)(double), const double x,
//                const double h) const override;
//   double Fourth(double (*func)(double), const double x,
//                 const double h) const override;

// public:
//   ErrorOrder errorOrder;
// };
// } // namespace PWP::lib::numeric_methods::derivate