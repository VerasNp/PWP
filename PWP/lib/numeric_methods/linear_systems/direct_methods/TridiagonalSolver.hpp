#pragma once

#include "Vector.hpp"
#include <vector>

namespace PWP::lib::numeric_methods::linear_systems::direct_methods {

/**
 * @brief Coefficients of a tridiagonal linear system A*y = d, A com dimensão n×n
 *
 * lower[i] é o coeficiente de y[i-1] na linha i (lower[0] não é usado)
 * diag[i] é o coeficiente de y[i] na linha i
 * upper[i] é o coeficiente de y[i+1] na linha i (upper[n-1] não é usado)
 */
struct TridiagonalSystem {
    std::vector<double> lower;
    std::vector<double> diag;
    std::vector<double> upper;
};

/**
 * @brief Resolve um sistema tridiagonal A*y = d pelo algoritmo de Thomas (eliminação
 * gaussiana especializada para matrizes tridiagonais, sem pivotamento)
 *
 * @param system Coeficientes das três diagonais, cada vetor com tamanho n
 * @param rhs Vetor d do lado direito, tamanho n
 * @return core::Vector Solução y, tamanho n
 */
auto solveTridiagonal(const TridiagonalSystem &system, const core::Vector &rhs) -> core::Vector;

} // namespace PWP::lib::numeric_methods::linear_systems::direct_methods
