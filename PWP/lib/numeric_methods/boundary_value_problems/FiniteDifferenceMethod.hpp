#pragma once

#include "LinearBVP.hpp"
#include "Vector.hpp"
#include <sys/types.h>

namespace PWP::lib::numeric_methods::boundary_value_problems {

/**
 * @brief Malha e solução aproximada de um PVC resolvido pelo Método das Diferenças
 * Finitas
 *
 * x contém os N+1 nós da malha (incluindo os nós de contorno x[0] e x[N]) e y contém
 * os valores aproximados de y(x) nesses mesmos nós.
 */
struct FiniteDifferenceResult {
    core::Vector x;
    core::Vector y;
};

/**
 * @brief Resolve um PVC linear de segunda ordem pelo Método das Diferenças Finitas
 * (MDF) com diferenças centrais
 *
 * Discretiza [a, b] em N subintervalos iguais (Passo 1), substitui y'(x) e y''(x)
 * pelas aproximações de diferenças centrais (Passo 2), monta o sistema tridiagonal
 * resultante da aplicação da máscara de coeficientes nos N-1 nós internos (Passo 3) e
 * o resolve pelo algoritmo de Thomas (Passo 4).
 *
 * @param problem PVC a ser resolvido
 * @param N Número de subintervalos da malha (N >= 2)
 * @return FiniteDifferenceResult Nós da malha e valores aproximados de y em cada nó
 */
auto solve(const LinearBVP &problem, uint N) -> FiniteDifferenceResult;

} // namespace PWP::lib::numeric_methods::boundary_value_problems
