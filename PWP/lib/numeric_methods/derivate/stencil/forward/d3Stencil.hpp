#pragma once

#include "derivate/stencil/Stencil.hpp"
namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil thirdForward2Points = {
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {-1.0, 3.0, -3.0, 1.0},
    .offset = {0, 1.0, 2.0, 3.0},
    .denominator = 1.0,
    .denominator_power = 3};

} // namespace PWP::lib::numeric_methods::derivate::stencil::forward