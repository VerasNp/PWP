#pragma once

#include "derivate/stencil/Stencil.hpp"
namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil secondForward3Points = {.derivateOrder =
                                                                    DerivativeOrder::Second,
                                                                .errorOrder = ErrorOrder::O_h,
                                                                .coefficient = {0, -2.0, 1.0},
                                                                .offset = {2.0, 1.0, 0},
                                                                .denominator = 1.0,
                                                                .denominator_power = 2};
inline const derivate::stencil::Stencil secondForward4Points = {
    .derivateOrder = DerivativeOrder::Second,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {2.0, -5.0, 4.0, -1.0},
    .offset = {0, 1.0, 2.0, 3.0},
    .denominator = 1.0,
    .denominator_power = 2};
inline const derivate::stencil::Stencil secondForward5Points = {
    .derivateOrder = DerivativeOrder::Second,
    .errorOrder = ErrorOrder::O_h3,
    .coefficient = {2.0, -5.0, 4.0, -1.0},
    .offset = {0, 1.0, 2.0, 3.0},
    .denominator = 1.0,
    .denominator_power = 2};

} // namespace PWP::lib::numeric_methods::derivate::stencil::forward