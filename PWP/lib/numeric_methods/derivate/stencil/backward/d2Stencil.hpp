#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::backward {

// f''(x) ≈ [f(x) - 2f(x-h) + f(x-2h)] / h²
inline const derivate::stencil::Stencil secondBackward3Points = {
    .derivateOrder = DerivativeOrder::Second,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {1.0, -2.0, 1.0},
    .offset = {0.0, -1.0, -2.0},
    .denominator = 1.0,
    .denominator_power = 2};

// f''(x) ≈ [2f(x) - 5f(x-h) + 4f(x-2h) - f(x-3h)] / h²
inline const derivate::stencil::Stencil secondBackward4Points = {
    .derivateOrder = DerivativeOrder::Second,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {2.0, -5.0, 4.0, -1.0},
    .offset = {0.0, -1.0, -2.0, -3.0},
    .denominator = 1.0,
    .denominator_power = 2};

// f''(x) ≈ [35f(x) - 104f(x-h) + 114f(x-2h) - 56f(x-3h) + 11f(x-4h)] / (12h²)
inline const derivate::stencil::Stencil secondBackward5Points = {
    .derivateOrder = DerivativeOrder::Second,
    .errorOrder = ErrorOrder::O_h3,
    .coefficient = {35.0, -104.0, 114.0, -56.0, 11.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0},
    .denominator = 12.0,
    .denominator_power = 2};

// f''(x) ≈ [45f(x) - 154f(x-h) + 214f(x-2h) - 156f(x-3h) + 61f(x-4h) - 10f(x-5h)] / (12h²)
inline const derivate::stencil::Stencil secondBackward6Points = {
    .derivateOrder = DerivativeOrder::Second,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {45.0, -154.0, 214.0, -156.0, 61.0, -10.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0},
    .denominator = 12.0,
    .denominator_power = 2};

} // namespace PWP::lib::numeric_methods::derivate::stencil::backward
