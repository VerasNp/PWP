#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include <utility>
namespace PWP::lib::numeric_methods::eigenvalue_problems {
class PowerMethod {
  public:
    /**
     * @brief Computes the largest eigenvalue and its corresponding eigenvector using the Power
     * Method.
     *
     * This iterative algorithm finds the dominant eigenvalue and eigenvector by repeatedly:
     * 1. Normalizing the current vector
     * 2. Multiplying the matrix by the normalized vector
     * 3. Computing the eigenvalue as the dot product of the normalized vector with the result
     * 4. Checking convergence by comparing consecutive eigenvalue estimates
     *
     * The iteration continues until the difference between consecutive eigenvalue estimates
     * is smaller than the specified threshold.
     *
     * **Algorithm Details:**
     * ```
     * while |λₖ - λₖ₋₁| > threshold:
     *     vₖ = normalize(vₖ₋₁)
     *     wₖ = A * vₖ
     *     λₖ = vₖ · wₖ
     *     error = |λₖ - λₖ₋₁|
     * ```
     *
     * **Computational Complexity:**
     * - Time: O(k × n²) where k is the number of iterations until convergence
     * - Space: O(n) for storing vectors and matrices
     *
     * **Convergence Analysis:**
     * The convergence rate depends on the ratio |λ₂/λ₁|, where λ₁ is the dominant eigenvalue
     * and λ₂ is the second largest. A ratio close to 1 results in slow convergence.
     * Convergence is linear with rate |λ₂/λ₁|.
     *
     * **Typical Iteration Counts:**
     * - For well-separated eigenvalues: 10-50 iterations
     * - For close eigenvalues: 100-1000+ iterations
     * - Threshold 1e-6 typically requires 20-100 iterations for reasonable matrices
     *
     * @param matrix A square n × n matrix for which to compute the dominant eigenvalue.
     *               The matrix should be square. Symmetric matrices exhibit better convergence
     *               properties. Non-symmetric matrices may have complex eigenvalues.
     *
     * @param vector An initial n-dimensional vector for iteration. Can be random or any vector
     *               that is not orthogonal to the principal eigenvector.
     *               The vector will be normalized in the first iteration.
     *               A good initial guess can accelerate convergence.
     *
     * @param threshold Convergence criterion. The method stops when
     *                  |eigenValueNew - eigenValueOld| < threshold.
     *
     *                  Recommended values:
     *                  - 1e-3: Low precision, 10-30 iterations
     *                  - 1e-6: Medium precision (default), 20-100 iterations
     *                  - 1e-9: High precision, 50-200 iterations
     *                  - 1e-12: Very high precision, 100-500+ iterations
     *
     * @return std::pair<double, PWP::lib::core::Vector> A pair containing:
     *         - **first**: The dominant eigenvalue λ₁ of the matrix (in magnitude)
     *         - **second**: The normalized eigenvector v₁ (unit magnitude = 1.0)
     *                      corresponding to the dominant eigenvalue
     *
     * @example
     * @code
     * // Example 1: Find eigenvalue of a 2×2 matrix
     * // Matrix A = [[4, 1], [1, 3]]
     * // Eigenvalues: λ₁ ≈ 4.618, λ₂ ≈ 2.382
     *
     * double matrixValues[] = {4, 1, 1, 3};
     * double vectorValues[] = {1, 1};
     *
     * PWP::lib::core::Matrix matrix(2, 2, matrixValues);
     * PWP::lib::core::Vector vector(2, vectorValues);
     *
     * auto [eigenValue, eigenVector] =
     *     PowerMethod::calculateRegular(matrix, vector, 1e-6);
     *
     * std::cout << "Eigenvalue: " << eigenValue << std::endl;      // Output: 4.618
     * std::cout << "Eigenvector[0]: " << eigenVector[0] << std::endl;
     * std::cout << "Eigenvector[1]: " << eigenVector[1] << std::endl;
     * @endcode
     *
     * @example
     * @code
     * // Example 2: Find eigenvalue of a 3×3 symmetric matrix
     * double matrixValues[] = {4, 1, 0, 1, 3, 1, 0, 1, 2};
     * double vectorValues[] = {1, 1, 1};
     *
     * PWP::lib::core::Matrix matrix(3, 3, matrixValues);
     * PWP::lib::core::Vector vector(3, vectorValues);
     *
     * auto result = PowerMethod::calculateRegular(matrix, vector, 1e-8);
     *
     * double lambda = result.first;
     * PWP::lib::core::Vector v = result.second;
     *
     * // Verify: A*v ≈ λ*v
     * PWP::lib::core::Vector Av = matrix * v;
     * PWP::lib::core::Vector lambda_v_scaled = v;
     * for (int i = 0; i < v.getSize(); i++) {
     *     lambda_v_scaled[i] *= lambda;
     * }
     * @endcode
     *
     * **Error Handling:**
     * No exceptions are thrown. If convergence is not achieved within reasonable iterations,
     * the method returns the last computed eigenvalue and eigenvector.
     *
     * **Limitations:**
     * - Cannot find complex eigenvalues directly
     * - Fails if initial vector is orthogonal to principal eigenvector
     * - Slow convergence when |λ₁/λ₂| ≈ 1
     * - Cannot find interior eigenvalues (use shifted inverse power method instead)
     *
     * **When to Use:**
     * - Finding the largest eigenvalue of a matrix
     * - Google PageRank computation
     * - Principal Component Analysis (PCA)
     * - Vibrational analysis (largest frequency)
     * - Graph centrality measures
     *
     * **When NOT to Use:**
     * - Need multiple eigenvalues (use QR algorithm or Jacobi method)
     * - Need interior eigenvalues (use shifted inverse power method)
     * - Matrix has complex eigenvalues with similar magnitudes
     *
     * @see Vector::normalize() - Normalizes vectors to unit length
     * @see Vector::dot() - Computes dot product for eigenvalue estimation
     * @see Matrix::operator*() - Matrix-vector multiplication used in iterations
     * @see Matrix::isSymmetric() - Check for symmetric matrices (better convergence)
     *
     * @warning
     * - **Orthogonal initial vector:** If the initial vector is orthogonal to the principal
     *   eigenvector, the method will fail due to numerical precision loss.
     *   Solution: Use a random initial vector or add small perturbations.
     *
     * - **Close eigenvalues:** When |λ₁| ≈ |λ₂|, convergence is extremely slow.
     *   Solution: Use deflation or shift-invert techniques.
     *
     * - **Non-symmetric matrices:** May not converge or converge to complex eigenvalues.
     *   Solution: Use Schur decomposition or Arnoldi iteration for non-symmetric cases.
     *
     * - **Nearly singular matrices:** Numerical instability may occur.
     *   Solution: Use QR decomposition or other stable methods.
     *
     * @note
     * **Performance Tips:**
     * - Start with a random initial vector for robustness
     * - Use threshold 1e-6 for most applications
     * - For sparse matrices, consider using sparse matrix formats
     * - Precompute matrix in optimized form if multiple iterations needed
     */
    auto static calculateRegular(core::Matrix matrix, core::Vector vector, double threshold)
        -> std::pair<double, PWP::lib::core::Vector>;

    auto static calculateInverse(core::Matrix matrix, core::Vector vector, double threshold)
        -> std::pair<double, PWP::lib::core::Vector>;
};
} // namespace PWP::lib::numeric_methods::eigenvalue_problems