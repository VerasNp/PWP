#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
namespace PWP::lib::numeric_methods::linear_systems {
/**
 * @brief Interface para solvers de sistemas lineares densos genéricos A*x = b
 *
 * Pensada para matrizes sem estrutura conhecida a priori (ex.: LUSolver). Sistemas com
 * estrutura especial (ex.: tridiagonal) devem usar um algoritmo especializado — ver
 * linear_systems/direct_methods/TridiagonalSolver.hpp — em vez de implementar esta
 * interface, para não pagar o custo O(n²) de memória / O(n³) de tempo de um solver denso.
 */
class ILinearSystem {
  public:
    virtual auto solve(core::Matrix &coefficientMatrix, core::Vector &constantVector)
        -> core::Vector = 0;
};
} // namespace PWP::lib::numeric_methods::linear_systems