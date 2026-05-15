#include "derivate/Derivate.hpp"
#include "derivate/DerivateBase.hpp"
#include "derivate/stencil/Stencil.hpp"
#include "derivate/stencil/forward/ForwardStencil.hpp"

using namespace PWP::lib::numeric_methods::derivate;

Derivate::Derivate(DerivativeOrder derivateOrder, ErrorOrder errorOrder) {
    this->derivateOrder_ = derivateOrder;
    this->errorOrder_ = errorOrder;
}

auto Derivate::calculate(double (*func)(double), double xValue, double hValue) const -> double {
    const stencil::Stencil &stencil =
        stencil::forward::get(this->derivateOrder_, this->errorOrder_);
    return stencil::apply(stencil, func, xValue, hValue);
}