#include "LUDecomposition.hpp"
#include "Vector.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <sys/types.h>

PWP::lib::numeric_methods::matrices_factorization::LUDecomposition::LUDecomposition(
    PWP::lib::core::Matrix &matrix)
    : luDecomposition_(matrix), permutation_(matrix.getRows()) {}

auto PWP::lib::numeric_methods::matrices_factorization::LUDecomposition::execute() -> core::Matrix {
    uint n = this->luDecomposition_.getRows();
    core::Vector scalingFactors(n);
    const double TINY = 1.0e-40;
    double big, temp;
    uint iMax;

    // Step 1: Find scaling factors for each row
    for (uint i = 0; i < n; i++) {
        big = 0.0;
        for (uint j = 0; j < n; j++) {
            temp = std::abs(this->luDecomposition_[i][j]);
            big = std::max(temp, big);
        }
        if (big == 0.0) {
            throw std::runtime_error("Singular matrix in LU decomposition");
        }
        scalingFactors[i] = 1.0 / big;
    }

    // Step 2: Perform LU decomposition with partial pivoting
    for (uint k = 0; k < n; k++) {
        big = 0.0;
        iMax = k;

        // Find pivot row
        for (uint i = k; i < n; i++) {
            temp = scalingFactors[i] * std::abs(this->luDecomposition_[i][k]);
            if (temp > big) {
                big = temp;
                iMax = i;
            }
        }

        // Swap rows if necessary
        if (k != iMax) {
            for (uint j = 0; j < n; j++) {
                temp = this->luDecomposition_[iMax][j];
                this->luDecomposition_[iMax][j] = this->luDecomposition_[k][j];
                this->luDecomposition_[k][j] = temp;
            }
            scalingFactors[iMax] = scalingFactors[k];
        }

        // Store permutation
        this->permutation_[k] = iMax;

        // Check for singular matrix
        if (std::abs(this->luDecomposition_[k][k]) < TINY) {
            this->luDecomposition_[k][k] = TINY;
        }

        // Eliminate column below pivot
        for (uint i = k + 1; i < n; i++) {
            temp = this->luDecomposition_[i][k] / this->luDecomposition_[k][k];
            this->luDecomposition_[i][k] = temp;

            for (uint j = k + 1; j < n; j++) {
                this->luDecomposition_[i][j] -= temp * this->luDecomposition_[k][j];
            }
        }
    }

    return this->luDecomposition_;
}