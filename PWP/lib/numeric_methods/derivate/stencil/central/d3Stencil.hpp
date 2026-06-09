#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::central {
inline const derivate::stencil::Stencil thirdCentral4Points = {
    .methodType = MethodType::Central,
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {-1.0, 2.0, -2.0, 1.0},
    .offset = {2.0, 1.0, -1.0, -2.0},
    .denominator = 2.0,
    .denominator_power = 3};
inline const derivate::stencil::Stencil thirdCentral6Points = {
    .methodType = MethodType::Central,
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {-1.0, 8.0, -13.0, 13.0, -8.0, 1.0},
    .offset = {3.0, 2.0, 1.0, -1.0, -2.0, -3.0},
    .denominator = 8.0,
    .denominator_power = 3};
} // namespace PWP::lib::numeric_methods::derivate::stencil::central