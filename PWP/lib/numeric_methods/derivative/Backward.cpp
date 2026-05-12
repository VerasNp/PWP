// #include "Backward.hpp"

// using namespace PWP::lib::numeric_methods::derivate;
// using namespace PWP::lib::numeric_methods::derivate::stencil;

// Backward::Backward(ErrorOrder errorOrder) { this->errorOrder = errorOrder; }

// double Backward::First(double (*func)(double), const double x,
//                        const double h) const {
//   Stencil stencil;
//   switch (this->errorOrder) {
//   case ErrorOrder::O_h:
//     stencil = stencil::firstBackwardXPoint;
//     break;
//   case ErrorOrder::O_h2:
//   case ErrorOrder::O_h3:
//   case ErrorOrder::O_h4:
//     break;
//   }
//   return stencil::apply(stencil, func, x, h)
// }