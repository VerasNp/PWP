#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::backward {

inline const derivate::stencil::Stencil firstBackward2Points = {
    .derivateOrder = DerivativeOrder::First,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {1.0, -1.0},
    .offset = {0.0, -1.0},
    .denominator = 1.0,
    .denominator_power = 1};

inline const derivate::stencil::Stencil firstBackward3Points = {
    .derivateOrder = DerivativeOrder::First,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {3.0, -4.0, 1.0},
    .offset = {0.0, -1.0, -2.0},
    .denominator = 2.0,
    .denominator_power = 1};

inline const derivate::stencil::Stencil firstBackward4Points = {
    .derivateOrder = DerivativeOrder::First,
    .errorOrder = ErrorOrder::O_h3,
    .coefficient = {11.0, -18.0, 9.0, -2.0},
    .offset = {0.0, -1.0, -2.0, -3.0},
    .denominator = 6.0,
    .denominator_power = 1};

inline const derivate::stencil::Stencil firstBackward5Points = {
    .derivateOrder = DerivativeOrder::First,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {25.0, -48.0, 36.0, -16.0, 3.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0},
    .denominator = 12.0,
    .denominator_power = 1};

} // namespace PWP::lib::numeric_methods::derivate::stencil::backward
