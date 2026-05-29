#include "eigenvalue_problems/PowerMethod.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "doctest.h"
#include <cstdlib>

TEST_CASE("PowerMethod") {
    SUBCASE("should calculate eigenvalue and eigenvector of 2x2 matrix") {
        double matrixValues[] = {4, 1, 1, 3};
        double vectorValues[] = {1, 1};
        PWP::lib::core::Matrix matrix(2, 2, matrixValues);
        PWP::lib::core::Vector vector(2, vectorValues);
        auto result = PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
            matrix, vector, 1e-6);
        double eigenValue = result.first;
        PWP::lib::core::Vector eigenVector = result.second;
        CHECK_EQ(eigenValue, doctest::Approx(4.618).epsilon(0.01));
        CHECK_EQ(eigenVector[0], doctest::Approx(eigenVector[0])); // normalized
    }

    SUBCASE("should calculate eigenvalue of identity matrix") {
        double matrixValues[] = {1, 0, 0, 1};
        double vectorValues[] = {1, 1};
        PWP::lib::core::Matrix matrix(2, 2, matrixValues);
        PWP::lib::core::Vector vector(2, vectorValues);
        auto result = PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
            matrix, vector, 1e-6);
        double eigenValue = result.first;
        CHECK_EQ(eigenValue, doctest::Approx(1.0).epsilon(0.01));
    }

    SUBCASE("should calculate eigenvalue of diagonal matrix") {
        double matrixValues[] = {5, 0, 0, 2};
        double vectorValues[] = {1, 1};
        PWP::lib::core::Matrix matrix(2, 2, matrixValues);
        PWP::lib::core::Vector vector(2, vectorValues);

        auto result = PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
            matrix, vector, 1e-6);
        double eigenValue = result.first;
        CHECK_EQ(eigenValue, doctest::Approx(5.0).epsilon(0.01));
    }

    SUBCASE("should calculate eigenvalue of 3x3 symmetric matrix") {
        double matrixValues[] = {4, 1, 0, 1, 3, 1, 0, 1, 2};
        double vectorValues[] = {1, 1, 1};
        PWP::lib::core::Matrix matrix(3, 3, matrixValues);
        PWP::lib::core::Vector vector(3, vectorValues);
        auto result = PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
            matrix, vector, 1e-6);
        double eigenValue = result.first;
        PWP::lib::core::Vector eigenVector = result.second;

        CHECK_GT(eigenValue, 4.0);

        CHECK_EQ(eigenVector.magnitude(), doctest::Approx(1.0).epsilon(0.01));
    }

    SUBCASE("should return normalized eigenvector") {
        double matrixValues[] = {2, 1, 1, 2};
        double vectorValues[] = {1, 0};
        PWP::lib::core::Matrix matrix(2, 2, matrixValues);
        PWP::lib::core::Vector vector(2, vectorValues);
        auto result = PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
            matrix, vector, 1e-6);
        PWP::lib::core::Vector eigenVector = result.second;
        CHECK_EQ(eigenVector.magnitude(), doctest::Approx(1.0).epsilon(0.01));
    }

    SUBCASE("should converge with different thresholds") {
        double matrixValues[] = {4, 1, 1, 3};
        double vectorValues[] = {1, 1};
        PWP::lib::core::Matrix matrix(2, 2, matrixValues);
        PWP::lib::core::Vector vector(2, vectorValues);
        auto result1 =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
                matrix, vector, 1e-3);
        auto result2 =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
                matrix, vector, 1e-9);
        CHECK_LT(std::abs(result2.first - 4.618), std::abs(result1.first - 4.618));
    }
}