#include "Forward.hpp"
#include "DerivateBase.hpp"

PWP::lib::numeric_methods::derivate::Forward::Forward(ErrorOrder errorOrder) {
    this->errorOrder = errorOrder;
}

auto PWP::lib::numeric_methods::derivate::Forward::First(double (*func)(double), double xValue,
                                                         double hValue) const -> double {
                                                            stencil::Stencil
                                                        }