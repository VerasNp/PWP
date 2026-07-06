#include "FiniteDifferenceMethod.hpp"
#include "linear_systems/direct_methods/TridiagonalSolver.hpp"
#include <stdexcept>

auto PWP::lib::numeric_methods::boundary_value_problems::solve(const LinearBVP &problem, uint N)
    -> FiniteDifferenceResult {
    if (N < 2) {
        throw std::invalid_argument("FiniteDifferenceMethod::solve: N deve ser >= 2");
    }

    double h = (problem.b - problem.a) / N;
    uint n = N - 1;

    core::Vector x(N + 1);
    for (uint i = 0; i <= N; i++) {
        x[i] = problem.a + i * h;
    }

    linear_systems::direct_methods::TridiagonalSystem system;
    system.lower.assign(n, 0.0);
    system.diag.assign(n, 0.0);
    system.upper.assign(n, 0.0);
    core::Vector rhs(n);

    for (uint k = 0; k < n; k++) {
        double xi = x[k + 1];
        double lowerCoeff = 1.0 - problem.p(xi) * h / 2.0;
        double diagCoeff = -2.0 + problem.q(xi) * h * h;
        double upperCoeff = 1.0 + problem.p(xi) * h / 2.0;

        system.diag[k] = diagCoeff;
        rhs[k] = problem.r(xi) * h * h;

        if (k > 0) {
            system.lower[k] = lowerCoeff;
        } else {
            rhs[k] -= lowerCoeff * problem.alpha;
        }

        if (k < n - 1) {
            system.upper[k] = upperCoeff;
        } else {
            rhs[k] -= upperCoeff * problem.beta;
        }
    }

    core::Vector innerY = linear_systems::direct_methods::solveTridiagonal(system, rhs);

    core::Vector y(N + 1);
    y[0] = problem.alpha;
    for (uint k = 0; k < n; k++) {
        y[k + 1] = innerY[k];
    }
    y[N] = problem.beta;

    return {x, y};
}
