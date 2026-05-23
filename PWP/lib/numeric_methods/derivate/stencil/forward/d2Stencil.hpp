#pragma once

#include "derivate/stencil/Stencil.hpp"
namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil secondForward3Points = {.derivateOrder =
                                                                    DerivativeOrder::Second,
                                                                .errorOrder = ErrorOrder::O_h,
                                                                .coefficient = {1.0, -2.0, 1.0},
                                                                .offset = {0, 1.0, 2.0},
                                                                .denominator = 1.0,
                                                                .denominator_power = 2};
inline const derivate::stencil::Stencil secondForward4Points = {};
inline const derivate::stencil::Stencil secondForward5Points = {};
inline const derivate::stencil::Stencil secondForward6Points = {};

} // namespace PWP::lib::numeric_methods::derivate::stencil::forward