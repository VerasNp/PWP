#include "Forward.hpp"
#include "DerivateBase.hpp"
#include "stencil/Stencil.hpp"

using namespace PWP::lib::numeric_methods::derivate;

Forward::Forward(DerivativeOrder derivateOrder, ErrorOrder errorOrder) {
    this->derivateOrder = derivateOrder;
    this->errorOrder = errorOrder;
}

auto Forward::calculate(double (*func)(double), double xValue, double hValue) const -> double {
    stencil::Stencil stencil;
    switch (this->errorOrder) {
    case ErrorOrder::O_h:
    case ErrorOrder::O_h2:
    case ErrorOrder::O_h3:
    case ErrorOrder::O_h4:
        break;
    }
}