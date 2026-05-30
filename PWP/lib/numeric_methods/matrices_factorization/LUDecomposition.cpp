#include "LUDecomposition.hpp"
#include "Vector.hpp"
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include <sys/types.h>

auto PWP::lib::numeric_methods::matrices_factorization::LUDecomposition::execute(
    PWP::lib::core::Matrix &matrix) -> PWP::lib::core::Matrix {
    PWP::lib::core::Matrix luMatrix(matrix);
    PWP::lib::core::Vector scalingFactors(matrix.getRows());
    PWP::lib::core::Vector permutation(matrix.getRows());
    const double TINY = 1.0e-40;
    double big, temp;
    int iMax;
    double determinant = 1.0;
    for (uint i = 0; i < matrix.getRows(); i++) {
        big = 0.0;
        for (uint j = 0; j < matrix.getColumns(); j++) {
            temp = std::abs(luMatrix[i][j]);
            big = std::max(temp, big);
        }
        if (big == 0.0) {
            throw std::runtime_error("Singular matrix in LU decomposition");
        }
        scalingFactors[i] = 1.0 / big;
    }
    for (uint k = 0; k < matrix.getRows(); k++) {
        big = 0.0;
        iMax = k;
        for (uint i = k; i < matrix.getRows(); i++) {
            temp = scalingFactors[i] * std::abs(luMatrix[i][k]);
            if (temp > big) {
                big = temp;
                iMax = i;
            }
        }
        if (k != iMax) {
            for (uint j = 0; j < matrix.getColumns(); j++) {
                temp = luMatrix[iMax][j];
                luMatrix[iMax][j] = luMatrix[k][j];
                luMatrix[k][j] = temp;
            }
            determinant = -determinant;
            scalingFactors[iMax] = scalingFactors[k];
        }
        permutation[k] = iMax;
        if (luMatrix[k][k] == 0.0) {
            luMatrix[k][k] = TINY;
        }
        for (uint i = k + 1; i < matrix.getRows(); i++) {
            temp = luMatrix[i][k] /= luMatrix[k][k];
            for (uint j = k + 1; j < matrix.getColumns(); j++) {
                luMatrix[i][j] -= temp * luMatrix[k][j];
            }
        }
    }
    return luMatrix;
}
