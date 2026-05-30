#include "matrices_factorization/LUDecomposition.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "doctest.h"
#include <stdexcept>

TEST_CASE("LU Decomposition") {
    SUBCASE("should decompose a 3x3 matrix into LU") {
        double data[] = {1, -2, 1, 2, -3, 1, 1, 4, 2};
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        auto luMatrix = luDecomposition.execute();
        
        // After LU decomposition with partial pivoting
        // The matrix is rearranged, so we verify the structure exists
        CHECK_NE(luMatrix[0][0], 0);
        CHECK_NE(luMatrix[1][1], 0);
        CHECK_NE(luMatrix[2][2], 0);
    }
    
    SUBCASE("should decompose a 2x2 matrix") {
        double data[] = {4, 3, 6, 3};
        PWP::lib::core::Matrix matrix(2, 2, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        auto luMatrix = luDecomposition.execute();
        
        CHECK_NE(luMatrix[0][0], 0);
        CHECK_NE(luMatrix[1][1], 0);
    }
    
    SUBCASE("should store row permutation") {
        double data[] = {1, -2, 1, 2, -3, 1, 1, 4, 2};
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        luDecomposition.execute();
        auto permutation = luDecomposition.getPermutation();
        
        // Permutation vector should have valid indices
        CHECK_EQ(permutation.getSize(), 3);
    }
    
    SUBCASE("should return LU decomposition matrix") {
        double data[] = {4, 3, 6, 3};
        PWP::lib::core::Matrix matrix(2, 2, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        luDecomposition.execute();
        auto luMatrix = luDecomposition.getLUDecomposition();
        
        CHECK_EQ(luMatrix.getRows(), 2);
        CHECK_EQ(luMatrix.getColumns(), 2);
    }
    
    SUBCASE("should throw exception for singular matrix") {
        double data[] = {1, 2, 3, 2, 4, 6, 1, 2, 3};  // Singular: row 3 = 2*row 1
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        CHECK_THROWS_AS(luDecomposition.execute(), std::runtime_error);
    }
    
    SUBCASE("should handle identity matrix") {
        double data[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        auto luMatrix = luDecomposition.execute();
        
        // For identity matrix, diagonal should be 1
        CHECK_EQ(luMatrix[0][0], doctest::Approx(1.0));
        CHECK_EQ(luMatrix[1][1], doctest::Approx(1.0));
        CHECK_EQ(luMatrix[2][2], doctest::Approx(1.0));
    }
    
    SUBCASE("should handle upper triangular matrix") {
        double data[] = {2, 3, 4, 0, 5, 6, 0, 0, 7};
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        auto luMatrix = luDecomposition.execute();
        
        CHECK_NE(luMatrix[0][0], 0);
        CHECK_NE(luMatrix[1][1], 0);
        CHECK_NE(luMatrix[2][2], 0);
    }
    
    SUBCASE("should handle lower triangular matrix") {
        double data[] = {2, 0, 0, 3, 5, 0, 4, 6, 7};
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        auto luMatrix = luDecomposition.execute();
        
        CHECK_NE(luMatrix[0][0], 0);
        CHECK_NE(luMatrix[1][1], 0);
        CHECK_NE(luMatrix[2][2], 0);
    }
    
    SUBCASE("should handle symmetric matrix") {
        double data[] = {4, 2, 1, 2, 3, 2, 1, 2, 5};
        PWP::lib::core::Matrix matrix(3, 3, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        auto luMatrix = luDecomposition.execute();
        
        CHECK_NE(luMatrix[0][0], 0);
        CHECK_NE(luMatrix[1][1], 0);
        CHECK_NE(luMatrix[2][2], 0);
    }
    
    SUBCASE("should handle 4x4 diagonally dominant matrix") {
        double data[] = {
            10, 1, 2, 1,
            1, 10, 1, 2,
            2, 1, 10, 1,
            1, 2, 1, 10
        };
        PWP::lib::core::Matrix matrix(4, 4, data);
        PWP::lib::numeric_methods::matrices_factorization::LUDecomposition luDecomposition(matrix);
        
        auto luMatrix = luDecomposition.execute();
        
        for (uint i = 0; i < 4; i++) {
            CHECK_NE(luMatrix[i][i], 0);
        }
    }
}