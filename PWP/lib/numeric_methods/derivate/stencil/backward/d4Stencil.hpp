#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::backward {

// f''''(x) ≈ [f(x) - 4f(x-h) + 6f(x-2h) - 4f(x-3h) + f(x-4h)] / h⁴
inline const derivate::stencil::Stencil fourthBackward5Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {1.0, -4.0, 6.0, -4.0, 1.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0},
    .denominator = 1.0,
    .denominator_power = 4};

// f''''(x) ≈ [3f(x) - 14f(x-h) + 26f(x-2h) - 24f(x-3h) + 11f(x-4h) - 2f(x-5h)] / h⁴
inline const derivate::stencil::Stencil fourthBackward6Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {3.0, -14.0, 26.0, -24.0, 11.0, -2.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0},
    .denominator = 1.0,
    .denominator_power = 4};

inline const derivate::stencil::Stencil fourthBackward7Points = {};
inline const derivate::stencil::Stencil fourthBackward8Points = {};

} // namespace PWP::lib::numeric_methods::derivate::stencil::backward
