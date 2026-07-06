#include "Householder.hpp"
#include <cmath>

auto PWP::lib::numeric_methods::transformations::Householder::apply(const core::Matrix &matrix)
    -> core::Matrix {
    core::Matrix result = matrix;
    int rows = result.getRows();
    int cols = result.getColumns();
    for (int k = 0; k < rows - 2; ++k) {
        core::Vector x(rows - k - 1);
        for (int i = k + 1; i < rows; ++i) {
            x[i - k - 1] = result[i][k];
        }
        double normX = 0.0;
        for (int i = 0; i < x.getSize(); ++i) {
            normX += x[i] * x[i];
        }
        normX = std::sqrt(normX);

        if (normX < 1e-14) {
            continue;
        }
        double alpha = (x[0] >= 0) ? -normX : normX;
        double r = std::sqrt(0.5 * (alpha * alpha - x[0] * alpha));
        if (r < 1e-14) {
            continue;
        }
        core::Vector v(x.getSize());
        v[0] = (x[0] - alpha) / (2.0 * r);
        for (int i = 1; i < v.getSize(); ++i) {
            v[i] = x[i] / (2.0 * r);
        }
        for (int j = 0; j < cols; ++j) {
            double dotProduct = 0.0;
            for (int i = 0; i < v.getSize(); ++i) {
                dotProduct += v[i] * result[k + 1 + i][j];
            }
            for (int i = 0; i < v.getSize(); ++i) {
                result[k + 1 + i][j] -= 2.0 * v[i] * dotProduct;
            }
        }
        for (int i = 0; i < rows; ++i) {
            double dotProduct = 0.0;
            for (int j = 0; j < v.getSize(); ++j) {
                dotProduct += v[j] * result[i][k + 1 + j];
            }
            for (int j = 0; j < v.getSize(); ++j) {
                result[i][k + 1 + j] -= 2.0 * v[j] * dotProduct;
            }
        }
    }
    return result;
}