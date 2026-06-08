#pragma once

#include "derivate/DerivateBase.hpp"
#include <cmath>
#include <vector>

namespace PWP::lib::numeric_methods::derivate::stencil {
struct Stencil {
    MethodType methodType;
    DerivativeOrder derivateOrder;
    ErrorOrder errorOrder;
    std::vector<double> coefficient;
    std::vector<double> offset;
    double denominator;
    int denominator_power;
};

inline auto apply(const Stencil &stencil, double (*func)(double), double xValue, double hValue)
    -> double {
    double sum = 0.0;
    for (std::size_t i = 0; i < stencil.coefficient.size(); ++i) {
        sum += stencil.coefficient[i] * func(xValue + (stencil.offset[i] * hValue));
    }
    double divisor = stencil.denominator * std::pow(hValue, stencil.denominator_power);
    return sum / divisor;
}
} // namespace PWP::lib::numeric_methods::derivate::stencil