#include "ForwardCreator.hpp"
#include "Forward.hpp"
#include <memory>

auto PWP::lib::numeric_methods::derivate::ForwardCreator::create(ErrorOrder errorOrder) const
    -> std::unique_ptr<IDerivate> {
    return std::make_unique<Forward>(errorOrder);
}