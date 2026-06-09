#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::central {
inline const derivate::stencil::Stencil firstCentral2Points = {.methodType = MethodType::Central,
                                                               .derivateOrder =
                                                                   DerivativeOrder::First,
                                                               .errorOrder = ErrorOrder::O_h2,
                                                               .coefficient = {1.0, -1.0},
                                                               .offset = {1.0, -1.0},
                                                               .denominator = 2.0,
                                                               .denominator_power = 1};
inline const derivate::stencil::Stencil firstCentral4Points = {
    .methodType = MethodType::Central,
    .derivateOrder = DerivativeOrder::First,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {1.0, -8.0, 8.0, -1.0},
    .offset = {-2.0, -1.0, 1.0, 2.0},
    .denominator = 12.0,
    .denominator_power = 1};
} // namespace PWP::lib::numeric_methods::derivate::stencil::central