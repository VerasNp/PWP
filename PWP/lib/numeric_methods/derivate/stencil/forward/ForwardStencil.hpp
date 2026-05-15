#pragma once
#include "derivate/stencil/Stencil.hpp"
#include "derivate/stencil/forward/d1Stencil.hpp"
#include "derivate/stencil/forward/d2Stencil.hpp"
#include "derivate/stencil/forward/d3Stencil.hpp"
#include "derivate/stencil/forward/d4Stencil.hpp"
#include <array>
#include <stdexcept>

namespace PWP::lib::numeric_methods::derivate::stencil::forward {

inline const std::array<Stencil, 16> lookupArray = {{
    firstForward2Points,
    firstForward3Points,
    firstForward4Points,
    firstForward5Points,
    secondForward2Points,
    secondForward3Points,
    thirdForward2Points,
    fourthForward2Points,
}};

inline auto get(DerivativeOrder derivateOrder, ErrorOrder errorOrder) -> const Stencil & {
    for (const auto &stencil : lookupArray) {
        if (stencil.derivateOrder == derivateOrder && stencil.errorOrder == errorOrder) {
            return stencil;
        }
    }
    throw std::invalid_argument("Stencil não encontrado");
}

} // namespace PWP::lib::numeric_methods::derivate::stencil::forward