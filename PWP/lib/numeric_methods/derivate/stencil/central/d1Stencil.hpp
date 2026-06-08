#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::central {
inline const derivate::stencil::Stencil firstCentral2Points = {.methodType = MethodType::Central,
                                                               .derivateOrder =
                                                                   DerivativeOrder::First,
                                                               .errorOrder = ErrorOrder::O_h2,
                                                               .coefficient = {0.5, -0.5},
                                                               .offset = {1.0, -1.0},
                                                               .denominator = 1.0,
                                                               .denominator_power = 1};
inline const derivate::stencil::Stencil firstCentral3Points = {};
inline const derivate::stencil::Stencil firstCentral4Points = {};
} // namespace PWP::lib::numeric_methods::derivate::stencil::central