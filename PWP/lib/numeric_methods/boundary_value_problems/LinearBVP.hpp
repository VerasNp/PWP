#pragma once

#include <functional>

namespace PWP::lib::numeric_methods::boundary_value_problems {

/**
 * @brief Problema de valor de contorno linear de segunda ordem, com condições de
 * contorno de Dirichlet
 *
 * Descreve a equação diferencial
 *
 *     y''(x) + p(x)*y'(x) + q(x)*y(x) = r(x),   x em [a, b]
 *     y(a) = alpha,   y(b) = beta
 *
 * O caso p(x) = 0 e r(x) = 0 recai na forma y''(x) + q(x)*y(x) = 0 usada como exemplo
 * canônico do Método das Diferenças Finitas (ex.: y'' - y = 0 corresponde a q(x) = -1).
 */
struct LinearBVP {
    std::function<double(double)> p; ///< Coeficiente de y'(x)
    std::function<double(double)> q; ///< Coeficiente de y(x)
    std::function<double(double)> r; ///< Termo não-homogêneo (lado direito)
    double a;                        ///< Extremidade inferior do domínio
    double b;                        ///< Extremidade superior do domínio
    double alpha;                    ///< Condição de contorno y(a) = alpha
    double beta;                     ///< Condição de contorno y(b) = beta
};

} // namespace PWP::lib::numeric_methods::boundary_value_problems
