#pragma once

#include <vector>

namespace PWP::lib::numeric_methods::integrate {

struct GaussRule {
    std::vector<double> nodes;
    std::vector<double> weights;
};

template<typename Fn>
double applyRule(const GaussRule& r, Fn f) {
    double sum = 0.0;
    for (std::size_t i = 0; i < r.nodes.size(); ++i)
        sum += r.weights[i] * f(r.nodes[i]);
    return sum;
}

template<typename Fn>
double applyRule(const GaussRule& r, Fn f, double a, double b) {
    double mid  = (a + b) / 2.0;
    double half = (b - a) / 2.0;
    double sum  = 0.0;
    for (std::size_t i = 0; i < r.nodes.size(); ++i)
        sum += r.weights[i] * f(mid + half * r.nodes[i]);
    return sum * half;
}

} // namespace PWP::lib::numeric_methods::integrate