#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::central {
inline const derivate::stencil::Stencil secondCentral3Points = {.methodType = MethodType::Central,
                                                                .derivateOrder =
                                                                    DerivativeOrder::Second,
                                                                .errorOrder = ErrorOrder::O_h2,
                                                                .coefficient = {1.0, -2.0, 1.0},
                                                                .offset = {1.0, 0, -1.0},
                                                                .denominator = 1.0,
                                                                .denominator_power = 2};
inline const derivate::stencil::Stencil secondCentral5Points = {
    .methodType = MethodType::Central,
    .derivateOrder = DerivativeOrder::Second,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {-1.0, 16.0, -30.0, 16.0, -1.0},
    .offset = {2.0, 1.0, 0, -1.0, -2.0},
    .denominator = 12.0,
    .denominator_power = 2};
} // namespace PWP::lib::numeric_methods::derivate::stencil::central