#include "Vector.hpp"
#include "doctest.h"

TEST_CASE("Vector") {
    SUBCASE("should initialize with given row and column numbers") {
        PWP::lib::core::Vector vector(3);
        CHECK_EQ(vector[0], 0);
        CHECK_EQ(vector[1], 0);
        CHECK_EQ(vector[2], 0);
    }
    SUBCASE("should initialize with given constant value") {
        PWP::lib::core::Vector vector(3, 3);
        CHECK_EQ(vector[0], 3);
        CHECK_EQ(vector[1], 3);
        CHECK_EQ(vector[2], 3);
    }
    SUBCASE("should change a specific value on index") {
        PWP::lib::core::Vector vector(3, 3);
        vector[1] = 1;
        CHECK_EQ(vector[1], 1);
    }
    SUBCASE("should initialize with given values") {
        double vectorValues[] = {0, 1, 2};
        PWP::lib::core::Vector vector(3, vectorValues);
        CHECK_EQ(vector[2], 2);
    }
    SUBCASE("should transpose a vector") {
        double vectorValues[] = {0, 1, 2};
        PWP::lib::core::Vector vector(2, vectorValues, PWP::lib::core::Vector::Orientation::Column);
        PWP::lib::core::Vector transposedVector = vector.transpose();
        CHECK_EQ(transposedVector.getSize(), vector.getSize());
        CHECK_EQ(transposedVector.getOrientation(), PWP::lib::core::Vector::Orientation::Row);
    }
    SUBCASE("should calculate magnitude of a vector") {
        double vectorValues[] = {3.0, 4.0};
        PWP::lib::core::Vector vector(2, vectorValues);
        CHECK_EQ(vector.magnitude(), doctest::Approx(5.0));
    }
    SUBCASE("should calculate magnitude of zero vector") {
        PWP::lib::core::Vector vector(3, 0.0);
        CHECK_EQ(vector.magnitude(), doctest::Approx(0.0));
    }
    SUBCASE("should normalize a vector") {
        double vectorValues[] = {3.0, 4.0};
        PWP::lib::core::Vector vector(2, vectorValues);
        PWP::lib::core::Vector normalized = vector.normalize();
        CHECK_EQ(normalized[0], doctest::Approx(0.6));
        CHECK_EQ(normalized[1], doctest::Approx(0.8));
    }
    SUBCASE("should calculate dot product") {
        double values1[] = {1.0, 2.0, 3.0};
        double values2[] = {4.0, 5.0, 6.0};
        PWP::lib::core::Vector vector1(3, values1);
        PWP::lib::core::Vector vector2(3, values2);
        CHECK_EQ(vector1.dot(vector2), doctest::Approx(32.0));
    }
    SUBCASE("should calculate dot product of orthogonal vectors") {
        double values1[] = {1.0, 0.0};
        double values2[] = {0.0, 1.0};
        PWP::lib::core::Vector vector1(2, values1);
        PWP::lib::core::Vector vector2(2, values2);
        CHECK_EQ(vector1.dot(vector2), doctest::Approx(0.0));
    }
    SUBCASE("should calculate dot product with itself equals magnitude squared") {
        double vectorValues[] = {3.0, 4.0};
        PWP::lib::core::Vector vector(2, vectorValues);
        CHECK_EQ(vector.dot(vector), doctest::Approx(25.0));
    }
}
