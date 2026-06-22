#pragma once

#include "integrate/Stencil.hpp"
#include <cmath>
#include <stdexcept>

namespace PWP::lib::numeric_methods::integrate {

inline double integrate(
    const Stencil& s,
    double (*f)(double),
    double a,
    double b,
    double tol     = 1e-6,
    int    max_iter = 50
) {
    int    N    = 1;
    double prev = applyQuadrature(s, f, a, b);

    for (int iter = 0; iter < max_iter; ++iter) {
        N *= 2;
        double dx   = (b - a) / N;
        double curr = 0.0;
        for (int i = 0; i < N; ++i)
            curr += applyQuadrature(s, f, a + i * dx, a + (i + 1) * dx);

        if (std::abs(curr - prev) / (std::abs(curr) + 1e-15) < tol)
            return curr;
        prev = curr;
    }

    throw std::runtime_error("integrate: não convergiu após " + std::to_string(max_iter) + " iterações");
}

} // namespace PWP::lib::numeric_methods::integrate
