#pragma once

#include <vector>

namespace PWP::lib::numeric_methods::integrate {

struct Stencil {
    std::vector<double> coefficient;
    std::vector<double> offset;
    double              denominator;
};

template<typename Fn>
double applyRule(const Stencil& s, Fn f, double a, double b) {
    double h   = b - a;
    double sum = 0.0;
    for (std::size_t i = 0; i < s.coefficient.size(); ++i)
        sum += s.coefficient[i] * f(a + s.offset[i] * h);
    return sum * h / s.denominator;
}

} // namespace PWP::lib::numeric_methods::integrate
