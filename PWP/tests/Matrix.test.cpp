#include "Matrix.hpp"
#include "doctest.h"

TEST_CASE("Matrix") {
    SUBCASE("should initialize with given row and column numbers") {
        PWP::lib::core::Matrix matrix(3, 3);
        CHECK_EQ(matrix[0][0], 0);
        CHECK_EQ(matrix[0][1], 0);
        CHECK_EQ(matrix[0][2], 0);
        CHECK_EQ(matrix[1][0], 0);
        CHECK_EQ(matrix[1][1], 0);
        CHECK_EQ(matrix[1][2], 0);
        CHECK_EQ(matrix[2][0], 0);
        CHECK_EQ(matrix[2][1], 0);
        CHECK_EQ(matrix[2][2], 0);
    }
    SUBCASE("should initialize with given constant value") {
        PWP::lib::core::Matrix matrix(3, 3, 3);
        CHECK_EQ(matrix[0][0], 3);
        CHECK_EQ(matrix[0][1], 3);
        CHECK_EQ(matrix[0][2], 3);
        CHECK_EQ(matrix[1][0], 3);
        CHECK_EQ(matrix[1][1], 3);
        CHECK_EQ(matrix[1][2], 3);
        CHECK_EQ(matrix[2][0], 3);
        CHECK_EQ(matrix[2][1], 3);
        CHECK_EQ(matrix[2][2], 3);
    }
    SUBCASE("should change a specific value on matrix") {
        PWP::lib::core::Matrix matrix(3, 3, 3);
        matrix[0][1] = 1;
        CHECK_EQ(matrix[0][1], 1);
    }
    SUBCASE("should initialize matrix with given values") {
        double matrixValues[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        PWP::lib::core::Matrix matrix(3, 3, matrixValues);
        CHECK_EQ(matrix[2][2], 8);
    }
    SUBCASE("should transpose a matrix") {
        double matrixValues[] = {0, 1, 2, 3};
        PWP::lib::core::Matrix matrix(2, 2, matrixValues);
        PWP::lib::core::Matrix transposedMatrix = matrix.transpose();
        CHECK_EQ(transposedMatrix[1][0], matrix[0][1]);
        CHECK_EQ(transposedMatrix[0][1], matrix[1][0]);
    }
    SUBCASE("should check if a matrix is symmetric") {
        double matrixValues[] = {0, 1, 2, 1, 3, 4, 2, 4, 5};
        PWP::lib::core::Matrix matrix(3, 3, matrixValues);
        CHECK(matrix.isSymmetric());
    }
    SUBCASE("should make a multiplication of a matrix with another") {
        double aValues[] = {1, 2, 3, 4, 5, 6};
        PWP::lib::core::Matrix aMatrix(2, 3, aValues);
        double bValues[] = {7, 8, 9, 10, 11, 12};
        PWP::lib::core::Matrix bMatrix(3, 2, bValues);
        PWP::lib::core::Matrix resultMatrix = aMatrix * bMatrix;
        CHECK_EQ(resultMatrix[0][0], 58);
        CHECK_EQ(resultMatrix[0][1], 64);
        CHECK_EQ(resultMatrix[1][0], 139);
        CHECK_EQ(resultMatrix[1][1], 154);
    }
    SUBCASE("should multiply matrix by vector") {
        double matrixValues[] = {1, 2, 3, 4, 5, 6};
        double vectorValues[] = {1, 2, 3};
        PWP::lib::core::Matrix matrix(2, 3, matrixValues);
        PWP::lib::core::Vector vector(3, vectorValues);
        PWP::lib::core::Vector result = matrix * vector;
        CHECK_EQ(result[0], 14);
        CHECK_EQ(result[1], 32);
    }
    SUBCASE("should multiply matrix by vector with ones") {
        double matrixValues[] = {1, 2, 3, 4};
        PWP::lib::core::Matrix matrix(2, 2, matrixValues);
        PWP::lib::core::Vector vector(2, 1.0);
        PWP::lib::core::Vector result = matrix * vector;
        CHECK_EQ(result[0], 3);
        CHECK_EQ(result[1], 7);
    }
}
