#include "matrices_factorization/QRDecomposition.hpp"
#include "transformations/Householder.hpp"
#include <algorithm>
#include <doctest.h>

static PWP::lib::core::Matrix buildSymmetricTestMatrix() {
    PWP::lib::core::Matrix matrix(4, 4);
    double values[4][4] = {
        {4, 1, -2, 2},
        {1, 2, 0, 1},
        {-2, 0, 3, -2},
        {2, 1, -2, -1},
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = values[i][j];
        }
    }
    return matrix;
}

TEST_CASE("QRDecomposition") {
    const double tolerance = 1e-6;
    using PWP::lib::numeric_methods::matrices_factorization::QRDecomposition;
    SUBCASE("Q é ortogonal (Q^T * Q = I)") {
        const auto matrix = buildSymmetricTestMatrix();
        QRDecomposition qr(matrix);
        qr.execute();
        auto Q = qr.getQ();
        auto QtQ = Q.transpose() * Q;
        int n = QtQ.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double expected = (i == j) ? 1.0 : 0.0;
                CHECK(QtQ[i][j] == doctest::Approx(expected).epsilon(tolerance));
            }
        }
    }
    SUBCASE("R é triangular superior") {
        const auto matrix = buildSymmetricTestMatrix();
        QRDecomposition qr(matrix);
        qr.execute();
        auto R = qr.getR();

        int rows = R.getRows();
        int cols = R.getColumns();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < std::min(i, cols); ++j) {
                CHECK(R[i][j] == doctest::Approx(0.0).epsilon(tolerance));
            }
        }
    }
    SUBCASE("Q * R reconstrói a matriz original") {
        const auto matrix = buildSymmetricTestMatrix();
        QRDecomposition qr(matrix);
        qr.execute();
        auto Q = qr.getQ();
        auto R = qr.getR();
        auto reconstructed = Q * R;
        int n = matrix.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                CHECK(reconstructed[i][j] == doctest::Approx(matrix[i][j]).epsilon(tolerance));
            }
        }
    }
    SUBCASE("não modifica a matriz original passada como entrada") {
        const auto matrix = buildSymmetricTestMatrix();
        auto original = matrix;
        QRDecomposition qr(matrix);
        qr.execute();
        int n = matrix.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                CHECK(matrix[i][j] == doctest::Approx(original[i][j]).epsilon(tolerance));
            }
        }
    }
}

TEST_CASE("Householder seguido de QRDecomposition (pipeline)") {
    const double tolerance = 1e-6;
    using PWP::lib::numeric_methods::matrices_factorization::QRDecomposition;
    using PWP::lib::numeric_methods::transformations::Householder;
    SUBCASE("QR reconstrói corretamente a matriz tridiagonalizada pelo Householder") {
        const auto A = buildSymmetricTestMatrix();
        auto T = Householder::apply(A);
        QRDecomposition qr(T);
        qr.execute();
        auto Q = qr.getQ();
        auto R = qr.getR();
        auto reconstructed = Q * R;
        int n = T.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                CHECK(reconstructed[i][j] == doctest::Approx(T[i][j]).epsilon(tolerance));
            }
        }
    }
    SUBCASE("Q permanece ortogonal quando a entrada é o resultado do Householder") {
        const auto A = buildSymmetricTestMatrix();
        auto T = Householder::apply(A);
        QRDecomposition qr(T);
        qr.execute();
        auto Q = qr.getQ();
        auto QtQ = Q.transpose() * Q;
        int n = QtQ.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double expected = (i == j) ? 1.0 : 0.0;
                CHECK(QtQ[i][j] == doctest::Approx(expected).epsilon(tolerance));
            }
        }
    }
    SUBCASE("R é triangular superior quando a entrada é o resultado do Householder") {
        const auto A = buildSymmetricTestMatrix();
        auto T = Householder::apply(A);
        QRDecomposition qr(T);
        qr.execute();
        auto R = qr.getR();
        int rows = R.getRows();
        int cols = R.getColumns();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < std::min(i, cols); ++j) {
                CHECK(R[i][j] == doctest::Approx(0.0).epsilon(tolerance));
            }
        }
    }
}