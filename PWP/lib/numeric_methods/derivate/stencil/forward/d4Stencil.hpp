#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil fourthForward2Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {1.0, -4.0, 6.0, -4.0, 1.0},
    .offset = {0.0, 1.0, 2.0, 3.0, 4.0},
    .denominator = 1.0,
    .denominator_power = 4};
} // namespace PWP::lib::numeric_methods::derivate::stencil::forward