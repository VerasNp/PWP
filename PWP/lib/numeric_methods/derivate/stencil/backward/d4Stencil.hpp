#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::backward {

inline const derivate::stencil::Stencil fourthBackward5Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {1.0, -4.0, 6.0, -4.0, 1.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0},
    .denominator = 1.0,
    .denominator_power = 4};

inline const derivate::stencil::Stencil fourthBackward6Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {3.0, -14.0, 26.0, -24.0, 11.0, -2.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0},
    .denominator = 1.0,
    .denominator_power = 4};

inline const derivate::stencil::Stencil fourthBackward7Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h3,
    .coefficient = {35.0, -186.0, 411.0, -484.0, 321.0, -114.0, 17.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0, -6.0},
    .denominator = 6.0,
    .denominator_power = 4};

inline const derivate::stencil::Stencil fourthBackward8Points = {
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {56.0, -333.0, 852.0, -1219.0, 1056.0, -555.0, 164.0, -21.0},
    .offset = {0.0, -1.0, -2.0, -3.0, -4.0, -5.0, -6.0, -7.0},
    .denominator = 6.0,
    .denominator_power = 4};

} // namespace PWP::lib::numeric_methods::derivate::stencil::backward
