#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil firstForward2Points = {.derivateOrder =
                                                                   DerivativeOrder::First,
                                                               .errorOrder = ErrorOrder::O_h,
                                                               .coefficient = {1, -1},
                                                               .offset = {1, 0},
                                                               .denominator = 1.0,
                                                               .denominator_power = 1};
inline const derivate::stencil::Stencil firstForward3Points = {.derivateOrder =
                                                                   DerivativeOrder::First,
                                                               .errorOrder = ErrorOrder::O_h2,
                                                               .coefficient = {-3.0, 4.0, -1.0},
                                                               .offset = {0, 1, 2.0},
                                                               .denominator = 2.0,
                                                               .denominator_power = 1};
inline const derivate::stencil::Stencil firstForward4Points = {
    .derivateOrder = DerivativeOrder::First,
    .errorOrder = ErrorOrder::O_h3,
    .coefficient = {-2.0, 9.0, -18.0, 11.0},
    .offset = {3.0, 2.0, 1.0, 0},
    .denominator = 6.0,
    .denominator_power = 1};
inline const derivate::stencil::Stencil firstForward5Points = {
    .derivateOrder = DerivativeOrder::First,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {-25.0, 48.0, -36.0, 16.0, -3.0},
    .offset = {0.0, 1.0, 2.0, 3.0, 4.0},
    .denominator = 12.0,
    .denominator_power = 1};
} // namespace PWP::lib::numeric_methods::derivate::stencil::forward