#pragma once

#include "integrate/QuadratureStencil.hpp"
#include "integrate/GaussRule.hpp"
#include <cmath>
#include <stdexcept>

namespace PWP::lib::numeric_methods::integrate {

template<typename Rule, typename Fn>
double integrate(
    const Rule& r,
    Fn          f,
    double      a,
    double      b,
    double      tol      = 1e-6,
    int         max_iter = 50
) {
    int    N    = 1;
    double prev = applyRule(r, f, a, b);

    for (int iter = 0; iter < max_iter; ++iter) {
        N *= 2;
        double dx   = (b - a) / N;
        double curr = 0.0;
        for (int i = 0; i < N; ++i)
            curr += applyRule(r, f, a + i * dx, a + (i + 1) * dx);

        if (std::abs(curr - prev) / (std::abs(curr) + 1e-15) < tol)
            return curr;
        prev = curr;
    }

    throw std::runtime_error("integrate: não convergiu após " + std::to_string(max_iter) + " iterações");
}

} // namespace PWP::lib::numeric_methods::integrate
