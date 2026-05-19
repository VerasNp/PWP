#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::backward {
inline const derivate::stencil::Stencil firstBackward2Points = {.derivateOrder =
                                                                    DerivativeOrder::First,
                                                                .errorOrder = ErrorOrder::O_h,
                                                                .coefficient = {1, -1},
                                                                .offset = {1, 0},
                                                                .denominator = 1.0,
                                                                .denominator_power = 1};
} // namespace PWP::lib::numeric_methods::derivate::stencil::backward