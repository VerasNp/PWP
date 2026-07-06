#include "matrices_factorization/QRDecomposition.hpp"
#include <cmath>

PWP::lib::numeric_methods::matrices_factorization::QRDecomposition::QRDecomposition(
    const core::Matrix &matrix)
    : matrix_(matrix), Q_(matrix.getRows(), matrix.getRows()),
      R_(matrix.getRows(), matrix.getColumns()) {}

auto PWP::lib::numeric_methods::matrices_factorization::QRDecomposition::execute() -> void {
    int rows = matrix_.getRows();
    int cols = matrix_.getColumns();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            Q_[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            R_[i][j] = matrix_[i][j];
        }
    }
    int steps = std::min(rows - 1, cols);
    for (int k = 0; k < steps; ++k) {
        core::Vector x(rows - k);
        for (int i = k; i < rows; ++i) {
            x[i - k] = R_[i][k];
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
        for (int j = k; j < cols; ++j) {
            double dotProduct = 0.0;
            for (int i = 0; i < v.getSize(); ++i) {
                dotProduct += v[i] * R_[k + i][j];
            }
            for (int i = 0; i < v.getSize(); ++i) {
                R_[k + i][j] -= 2.0 * v[i] * dotProduct;
            }
        }
        for (int i = 0; i < rows; ++i) {
            double dotProduct = 0.0;
            for (int j = 0; j < v.getSize(); ++j) {
                dotProduct += v[j] * Q_[i][k + j];
            }
            for (int j = 0; j < v.getSize(); ++j) {
                Q_[i][k + j] -= 2.0 * v[j] * dotProduct;
            }
        }
    }
}