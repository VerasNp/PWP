#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil firstForward2Points = {.methodType = MethodType::Forward,
                                                               .derivateOrder =
                                                                   DerivativeOrder::First,
                                                               .errorOrder = ErrorOrder::O_h,
                                                               .coefficient = {-1.0, 1.0},
                                                               .offset = {0, 1.0},
                                                               .denominator = 1.0,
                                                               .denominator_power = 1};
inline const derivate::stencil::Stencil firstForward3Points = {.methodType = MethodType::Forward,
                                                               .derivateOrder =
                                                                   DerivativeOrder::First,
                                                               .errorOrder = ErrorOrder::O_h2,
                                                               .coefficient = {-3.0, 4.0, -1.0},
                                                               .offset = {0, 1.0, 2.0},
                                                               .denominator = 2.0,
                                                               .denominator_power = 1};
inline const derivate::stencil::Stencil firstForward4Points = {};
inline const derivate::stencil::Stencil firstForward5Points = {};
} // namespace PWP::lib::numeric_methods::derivate::stencil::forward