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
}
