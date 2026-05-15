#pragma once

#include "DerivateBase.hpp"
#include "IDerivate.hpp"
#include <memory>

namespace PWP::lib::numeric_methods::derivate {
class IDerivateCreator {
  public:
    [[nodiscard]] virtual auto create(DerivativeOrder derivateOrder, ErrorOrder errorOrder) const
        -> std::unique_ptr<IDerivate> = 0;
};
} // namespace PWP::lib::numeric_methods::derivate