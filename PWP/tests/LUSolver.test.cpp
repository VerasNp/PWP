#include "linear_systems/direct_methods/LUSolver.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "doctest.h"

TEST_CASE("LU Solver") {
    using namespace PWP::lib::numeric_methods::linear_systems::direct_methods;
    
    SUBCASE("should solve 2x2 linear system") {
        double matrixData[] = {4, 3, 6, 3};
        double vectorData[] = {10, 11};
        
        PWP::lib::core::Matrix A(2, 2, matrixData);
        PWP::lib::core::Vector b(2, vectorData);
        
        LUSolver solver;
        PWP::lib::core::Vector x = solver.solve(A, b);
        
        // Expected solution: x = 0.5, y = 2.666...
        CHECK_EQ(x[0], doctest::Approx(0.5).epsilon(1e-6));
        CHECK_EQ(x[1], doctest::Approx(2.666666).epsilon(1e-5));
    }
    
}