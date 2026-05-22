#pragma once
#include "derivate/stencil/Stencil.hpp"
#include "derivate/stencil/central/d1Stencil.hpp"
#include "derivate/stencil/central/d2Stencil.hpp"
#include "derivate/stencil/central/d3Stencil.hpp"
#include "derivate/stencil/central/d4Stencil.hpp"
#include <array>
#include <stdexcept>

namespace PWP::lib::numeric_methods::derivate::stencil::central {

inline const std::array<Stencil, 16> lookupArray = {
    {firstCentral2Points, firstCentral3Points, firstCentral4Points, firstCentral5Points,
     secondCentral3Points, secondCentral4Points, secondCentral5Points, secondCentral6Points,
     thirdCentral4Points, thirdCentral5Points, thirdCentral6Points, thirdCentral7Points,
     fourthCentral5Points, fourthCentral6Points, fourthCentral7Points, fourthCentral8Points}};

inline auto get(DerivativeOrder derivateOrder, ErrorOrder errorOrder) -> const Stencil & {
    for (const auto &stencil : lookupArray) {
        if (stencil.derivateOrder == derivateOrder && stencil.errorOrder == errorOrder) {
            return stencil;
        }
    }
    throw std::invalid_argument("Stencil não encontrado");
}

} // namespace PWP::lib::numeric_methods::derivate::stencil::central