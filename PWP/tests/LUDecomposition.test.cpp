#include "matrices_factorization/LUDecomposition.hpp"
#include "Matrix.hpp"
#include "doctest.h"

TEST_CASE("LU Decomposition") {
    SUBCASE("should decompose a matrix into LU") {
        double data[] = {1, -2, 1, 2, -3, 1, 1, 4, 2};
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition;
        auto luMatrix = luDecomposition.execute(matrix);
        CHECK_EQ(luMatrix[0][0], doctest::Approx(2));
        CHECK_EQ(luMatrix[0][1], doctest::Approx(-3));
        CHECK_EQ(luMatrix[0][2], doctest::Approx(1));
        CHECK_EQ(luMatrix[1][0], doctest::Approx(0.5));
        CHECK_EQ(luMatrix[1][1], doctest::Approx(5.5));
        CHECK_EQ(luMatrix[1][2], doctest::Approx(1.5));
        CHECK_EQ(luMatrix[2][0], doctest::Approx(0.5));
        CHECK_EQ(luMatrix[2][1], doctest::Approx(doctest::Approx(-1.0 / 11.0)));
        CHECK_EQ(luMatrix[2][2], doctest::Approx(7.0 / 11.0));
    }
}