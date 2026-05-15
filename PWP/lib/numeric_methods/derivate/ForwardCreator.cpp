#include "ForwardCreator.hpp"
#include "Forward.hpp"
#include <memory>

auto PWP::lib::numeric_methods::derivate::ForwardCreator::create(DerivativeOrder derivateOrder,
                                                                 ErrorOrder errorOrder) const
    -> std::unique_ptr<IDerivate> {
    return std::make_unique<Forward>(derivateOrder, errorOrder);
}