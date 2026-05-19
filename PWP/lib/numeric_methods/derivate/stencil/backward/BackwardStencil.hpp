#pragma once
#include "derivate/stencil/Stencil.hpp"
#include "derivate/stencil/backward/d1Stencil.hpp"
#include <array>
#include <stdexcept>

namespace PWP::lib::numeric_methods::derivate::stencil::backward {

inline const std::array<Stencil, 16> lookupArray = {{
    firstBackward2Points
}};

inline auto get(DerivativeOrder derivateOrder, ErrorOrder errorOrder) -> const Stencil & {
    for (const auto &stencil : lookupArray) {
        if (stencil.derivateOrder == derivateOrder && stencil.errorOrder == errorOrder) {
            return stencil;
        }
    }
    throw std::invalid_argument("Stencil não encontrado");
}

} // namespace PWP::lib::numeric_methods::derivate::stencil::backward