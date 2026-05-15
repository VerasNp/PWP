#pragma once

#include <cmath>
#include <vector>

namespace PWP::lib::numeric_methods::derivate::stencil {
struct Stencil {
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
    return sum / (stencil.denominator * std::pow(hValue, stencil.denominator_power));
}

inline const Stencil firstForward2Points = {{1, -1}, {1, 0}, 1.0, 1};
inline const Stencil firstForward3Points = {{-3.0, 4.0, -1.0}, {0, 1, 2.0}, 2.0, 1};
inline const Stencil secondForward2Points = {{1.0, -2.0, 1.0}, {2.0, 1.0, 0}, 1.0, 2};
inline const Stencil thirdForward2Points = {{1.0, -3.0, 3.0, -1.0}, {3.0, 2.0, 1.0, 0}, 1.0, 3};
inline const Stencil fourthForward2Points = {
    {1.0, -4.0, 6.0, -4.0, 1.0}, {4.0, 3.0, 2.0, 1.0, 0.0}, 1.0, 4};
} // namespace PWP::lib::numeric_methods::derivate::stencil