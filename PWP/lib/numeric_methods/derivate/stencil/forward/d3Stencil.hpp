#pragma once

#include "derivate/stencil/Stencil.hpp"
namespace PWP::lib::numeric_methods::derivate::stencil::forward {
inline const derivate::stencil::Stencil thirdForward4Points = {
    .derivateOrder = DerivativeOrder::Third,
    .errorOrder = ErrorOrder::O_h,
    .coefficient = {-1.0, 3.0, -3.0, 1.0},
    .offset = {0, 1.0, 2.0, 3.0},
    .denominator = 1.0,
    .denominator_power = 3
};
inline const derivate::stencil::Stencil thirdForward5Points = {};
inline const derivate::stencil::Stencil thirdForward6Points = {};
inline const derivate::stencil::Stencil thirdForward7Points = {};

} // namespace PWP::lib::numeric_methods::derivate::stencil::forward