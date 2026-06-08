#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::backward {

inline const derivate::stencil::Stencil thirdBackward4Points = {
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {1.0, -3.0, 3.0, -1.0},
    .offset = {0.0, -1.0, -2.0, -3.0},
    .denominator = 1.0,
    .denominator_power = 3};

inline const derivate::stencil::Stencil thirdBackward5Points = {
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {5.0, -18.0, 24.0, -14.0, 3.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0},
    .denominator = 2.0,
    .denominator_power = 3};

inline const derivate::stencil::Stencil thirdBackward6Points = {
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h3,
    .coefficient = {17.0, -71.0, 118.0, -98.0, 41.0, -7.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0},
    .denominator = 4.0,
    .denominator_power = 3};

inline const derivate::stencil::Stencil thirdBackward7Points = {
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {49.0, -232.0, 461.0, -496.0, 307.0, -104.0, 15.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0, -6.0},
    .denominator = 8.0,
    .denominator_power = 3};

} // namespace PWP::lib::numeric_methods::derivate::stencil::backward
