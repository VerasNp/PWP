#pragma once
#include "derivate/stencil/Stencil.hpp"
#include "derivate/stencil/central/d1Stencil.hpp"
#include "derivate/stencil/central/d2Stencil.hpp"
#include "derivate/stencil/central/d3Stencil.hpp"
#include "derivate/stencil/central/d4Stencil.hpp"
#include <array>
#include <stdexcept>

namespace PWP::lib::numeric_methods::derivate::stencil::central {

inline const std::array<Stencil, 8> lookupArray = {
    {firstCentral2Points, firstCentral4Points, secondCentral3Points, secondCentral5Points,
     thirdCentral4Points, thirdCentral6Points, fourthCentral5Points, fourthCentral7Points}};

inline auto get(DerivativeOrder derivateOrder, ErrorOrder errorOrder) -> const Stencil & {
    for (const auto &stencil : lookupArray) {
        if (stencil.derivateOrder == derivateOrder && stencil.errorOrder == errorOrder) {
            return stencil;
        }
    }
    throw std::invalid_argument("Stencil não encontrado");
}

} // namespace PWP::lib::numeric_methods::derivate::stencil::central