#pragma once
#include "derivate/stencil/Stencil.hpp"
#include "derivate/stencil/backward/d1Stencil.hpp"
#include "derivate/stencil/backward/d2Stencil.hpp"
#include "derivate/stencil/backward/d3Stencil.hpp"
#include "derivate/stencil/backward/d4Stencil.hpp"
#include <array>
#include <stdexcept>

namespace PWP::lib::numeric_methods::derivate::stencil::backward {

inline const std::array<Stencil, 16> lookupArray = {
    {firstBackward2Points, firstBackward3Points, firstBackward4Points, firstBackward5Points,
     secondBackward3Points, secondBackward4Points, secondBackward5Points, secondBackward6Points,
     thirdBackward4Points, thirdBackward5Points, thirdBackward6Points, thirdBackward7Points,
     fourthBackward5Points, fourthBackward6Points, fourthBackward7Points, fourthBackward8Points}};

inline auto get(DerivativeOrder derivateOrder, ErrorOrder errorOrder) -> const Stencil & {
    for (const auto &stencil : lookupArray) {
        if (stencil.derivateOrder == derivateOrder && stencil.errorOrder == errorOrder) {
            return stencil;
        }
    }
    throw std::invalid_argument("Stencil não encontrado");
}

} // namespace PWP::lib::numeric_methods::derivate::stencil::backward