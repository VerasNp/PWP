#include "transformations/Householder.hpp"
#include <cstdlib>
#include <doctest.h>

static double matrixTrace(const PWP::lib::core::Matrix &matrix) {
    double trace = 0.0;
    int n = matrix.getRows();
    for (int i = 0; i < n; ++i) {
        trace += matrix[i][i];
    }
    return trace;
}

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

static PWP::lib::core::Matrix buildTridiagonalTestMatrix() {
    PWP::lib::core::Matrix matrix(4, 4);
    double values[4][4] = {
        {2, 1, 0, 0},
        {1, 3, 1, 0},
        {0, 1, 4, 1},
        {0, 0, 1, 2},
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = values[i][j];
        }
    }
    return matrix;
}

TEST_CASE("Householder::apply") {
    const double tolerance = 1e-6;
    using PWP::lib::numeric_methods::transformations::Householder;
    SUBCASE("produz uma matriz tridiagonal a partir de uma matriz simétrica") {
        const auto matrix = buildSymmetricTestMatrix();
        auto result = Householder::apply(matrix);
        int n = result.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (std::abs(i - j) > 1) {
                    CHECK(result[i][j] == doctest::Approx(0.0).epsilon(tolerance));
                }
            }
        }
    }

    SUBCASE("preserva o traço (invariante de transformação de similaridade)") {
        const auto matrix = buildSymmetricTestMatrix();
        double traceBefore = matrixTrace(matrix);

        auto result = Householder::apply(matrix);

        CHECK(matrixTrace(result) == doctest::Approx(traceBefore).epsilon(tolerance));
    }

    SUBCASE("preserva a simetria da matriz original") {
        const auto matrix = buildSymmetricTestMatrix();
        auto result = Householder::apply(matrix);

        int n = result.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                CHECK(result[i][j] == doctest::Approx(result[j][i]).epsilon(tolerance));
            }
        }
    }
    SUBCASE("não modifica a matriz original, apenas retorna uma nova matriz transformada") {
        const auto matrix = buildSymmetricTestMatrix();
        auto original = matrix;

        auto result = Householder::apply(matrix);

        // matrix (entrada) permanece intocada
        int n = matrix.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                CHECK(matrix[i][j] == doctest::Approx(original[i][j]).epsilon(tolerance));
            }
        }
        bool isDifferent = false;
        for (int i = 0; i < n && !isDifferent; ++i) {
            for (int j = 0; j < n && !isDifferent; ++j) {
                if (std::abs(result[i][j] - matrix[i][j]) > tolerance) {
                    isDifferent = true;
                }
            }
        }
        CHECK(isDifferent);
    }
    SUBCASE("mantém uma matriz já tridiagonal inalterada") {
        const auto matrix = buildTridiagonalTestMatrix();
        auto result = Householder::apply(matrix);
        int n = result.getRows();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (std::abs(i - j) > 1) {
                    CHECK(result[i][j] == doctest::Approx(0.0).epsilon(tolerance));
                } else {
                    CHECK(std::abs(result[i][j]) ==
                          doctest::Approx(std::abs(matrix[i][j])).epsilon(tolerance));
                }
            }
        }
    }
}