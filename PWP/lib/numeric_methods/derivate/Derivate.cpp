#include "derivate/Derivate.hpp"
#include "derivate/DerivateBase.hpp"
#include "derivate/stencil/Stencil.hpp"
#include "derivate/stencil/forward/ForwardStencil.hpp"

using namespace PWP::lib::numeric_methods::derivate;

Derivate::Derivate(MethodType methodType, DerivativeOrder derivateOrder, ErrorOrder errorOrder) {
    this->methodType_ = methodType;
    this->derivateOrder_ = derivateOrder;
    this->errorOrder_ = errorOrder;
}

auto Derivate::calculate(double (*func)(double), double xValue, double hValue) const -> double {
    stencil::Stencil stencil;
    switch (this->methodType_) {
    case MethodType::Forward:
        stencil = stencil::forward::get(this->derivateOrder_, this->errorOrder_);
        break;
    case MethodType::Backward:
        throw std::invalid_argument("Método Backward não implementado");
        break;
    case MethodType::Central:
        throw std::invalid_argument("Método Backward não implementado");
        break;
    }
    return stencil::apply(stencil, func, xValue, hValue);
}