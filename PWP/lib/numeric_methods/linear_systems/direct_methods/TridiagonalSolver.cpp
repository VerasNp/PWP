#include "TridiagonalSolver.hpp"
#include <stdexcept>
#include <string>
#include <sys/types.h>

auto PWP::lib::numeric_methods::linear_systems::direct_methods::solveTridiagonal(
    const TridiagonalSystem &system, const core::Vector &rhs) -> core::Vector {
    uint n = rhs.getSize();
    if (n == 0) {
        throw std::invalid_argument("solveTridiagonal: sistema vazio");
    }

    std::vector<double> upperPrime(n);
    std::vector<double> rhsPrime(n);

    if (system.diag[0] == 0) {
        throw std::runtime_error("solveTridiagonal: pivô nulo na linha 0");
    }
    upperPrime[0] = system.upper[0] / system.diag[0];
    rhsPrime[0] = rhs[0] / system.diag[0];

    for (uint i = 1; i < n; i++) {
        double denominator = system.diag[i] - system.lower[i] * upperPrime[i - 1];
        if (denominator == 0) {
            throw std::runtime_error("solveTridiagonal: pivô nulo na linha " + std::to_string(i));
        }
        upperPrime[i] = system.upper[i] / denominator;
        rhsPrime[i] = (rhs[i] - system.lower[i] * rhsPrime[i - 1]) / denominator;
    }

    core::Vector y(n);
    y[n - 1] = rhsPrime[n - 1];
    for (uint i = n - 1; i > 0; i--) {
        y[i - 1] = rhsPrime[i - 1] - upperPrime[i - 1] * y[i];
    }

    return y;
}
