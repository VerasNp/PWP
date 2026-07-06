#pragma once

#include "derivate/stencil/Stencil.hpp"

namespace PWP::lib::numeric_methods::derivate::stencil::central {
inline const derivate::stencil::Stencil fourthCentral5Points = {
    .methodType = MethodType::Central,
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h2,
    .coefficient = {1.0, -4.0, 6.0, -4.0, 1.0},
    .offset = {2.0, 1.0, 0, -1.0, -2.0},
    .denominator = 1.0,
    .denominator_power = 4};
inline const derivate::stencil::Stencil fourthCentral7Points = {
    .methodType = MethodType::Central,
    .derivateOrder = DerivativeOrder::Fourth,
    .errorOrder = ErrorOrder::O_h4,
    .coefficient = {-1.0, 12.0, -39.0, 56.0, -39.0, 12.0, -1.0},
    .offset = {3.0, 2.0, 1.0, 0, -1.0, -2.0, -3.0},
    .denominator = 6.0,
    .denominator_power = 4};
} // namespace PWP::lib::numeric_methods::derivate::stencil::central