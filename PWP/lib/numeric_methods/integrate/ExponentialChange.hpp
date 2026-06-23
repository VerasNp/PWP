#pragma once

#include "integrate/QuadratureStencil.hpp"
#include "integrate/GaussRule.hpp"
#include <cmath>
#include <numbers>
#include <stdexcept>

namespace PWP::lib::numeric_methods::integrate::ExponentialChange {

namespace detail {

template <typename Rule, typename Fn>
double adaptiveIntegrate(const Rule& rule, Fn f, double a, double b,
                         double tol = 1e-6, int max_iter = 50) {
    int    N    = 1;
    double prev = applyRule(rule, f, a, b);
    for (int iter = 0; iter < max_iter; ++iter) {
        N *= 2;
        double dx   = (b - a) / N;
        double curr = 0.0;
        for (int i = 0; i < N; ++i)
            curr += applyRule(rule, f, a + i * dx, a + (i + 1) * dx);
        if (std::abs(curr - prev) / (std::abs(curr) + 1e-15) < tol)
            return curr;
        prev = curr;
    }
    throw std::runtime_error("ExponentialChange: não convergiu");
}

} // namespace detail

// x(s) = (a+b)/2 + (b-a)/2 * tanh(s),  s ∈ [-c, c]
// dx/ds = (b-a)/2 * sech²(s)
// Bom para singularidades unilaterais (endpoint único)
template <typename Rule, typename Fn>
double simpleExp(Fn f, double a, double b, const Rule& rule,
                 double c = 8.0, double tol = 1e-6) {
    const double mid  = (a + b) / 2.0;
    const double half = (b - a) / 2.0;
    auto g = [=](double t) -> double {
        double ch = std::cosh(t);
        double x  = mid + half * std::tanh(t);
        return f(x) * half / (ch * ch);
    };
    return detail::adaptiveIntegrate(rule, g, -c, c, tol);
}

// x(s) = (a+b)/2 + (b-a)/2 * tanh(π/2 * sinh(s)),  s ∈ [-c, c]
// dx/ds = (b-a)/2 * π/2 * cosh(s) * sech²(π/2 * sinh(s))
// Bom para singularidades bilaterais (ambos endpoints)
// Limitar c ≤ 3.5 para evitar overflow em cosh(π/2 * sinh(s))
template <typename Rule, typename Fn>
double doubleExp(Fn f, double a, double b, const Rule& rule,
                 double c = 3.0, double tol = 1e-6) {
    static constexpr double PI_2 = std::numbers::pi / 2.0;
    const double mid  = (a + b) / 2.0;
    const double half = (b - a) / 2.0;
    auto g = [=](double t) -> double {
        double w    = PI_2 * std::sinh(t);
        double ch_w = std::cosh(w);
        double x    = mid + half * std::tanh(w);
        double dxdt = half * PI_2 * std::cosh(t) / (ch_w * ch_w);
        return f(x) * dxdt;
    };
    return detail::adaptiveIntegrate(rule, g, -c, c, tol);
}

} // namespace PWP::lib::numeric_methods::integrate::ExponentialChange
