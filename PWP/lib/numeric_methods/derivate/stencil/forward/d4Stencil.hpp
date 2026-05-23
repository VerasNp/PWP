#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil fourthForward5Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {1.0, -4.0, 6.0, -4.0, 1.0},
    .offset = {0, 1.0, 2.0, 3.0, 4.0},
    .denominator = 1.0,
    .denominator_power = 4
};
inline const derivate::stencil::Stencil fourthForward6Points = {};
inline const derivate::stencil::Stencil fourthForward7Points = {};
inline const derivate::stencil::Stencil fourthForward8Points = {};
} // namespace PWP::lib::numeric_methods::derivate::stencil::forward