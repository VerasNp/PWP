#include "linear_systems/direct_methods/TridiagonalSolver.hpp"
#include "doctest.h"

using namespace PWP::lib::numeric_methods::linear_systems::direct_methods;
using PWP::lib::core::Vector;

TEST_CASE("solveTridiagonal — matriz tridiagonal simétrica 3x3") {
    // | 2 -1  0 |   |1|
    // |-1  2 -1 | = |0|
    // | 0 -1  2 |   |1|
    // solução exata: y = [1, 1, 1]
    TridiagonalSystem system;
    system.lower = {0.0, -1.0, -1.0};
    system.diag = {2.0, 2.0, 2.0};
    system.upper = {-1.0, -1.0, 0.0};

    double rhsData[] = {1.0, 0.0, 1.0};
    Vector rhs(3, rhsData);

    Vector y = solveTridiagonal(system, rhs);

    CHECK(y[0] == doctest::Approx(1.0).epsilon(1e-9));
    CHECK(y[1] == doctest::Approx(1.0).epsilon(1e-9));
    CHECK(y[2] == doctest::Approx(1.0).epsilon(1e-9));
}

TEST_CASE("solveTridiagonal — sistema 1x1") {
    TridiagonalSystem system;
    system.lower = {0.0};
    system.diag = {4.0};
    system.upper = {0.0};

    double rhsData[] = {8.0};
    Vector rhs(1, rhsData);

    Vector y = solveTridiagonal(system, rhs);

    CHECK(y[0] == doctest::Approx(2.0).epsilon(1e-9));
}

TEST_CASE("solveTridiagonal — assimétrica, verificação por substituição direta") {
    // | 4  1  0  0 |   |1|
    // | 1  4  1  0 | = |2|
    // | 0  2  4  1 |   |3|
    // | 0  0  1  4 |   |4|
    TridiagonalSystem system;
    system.lower = {0.0, 1.0, 2.0, 1.0};
    system.diag = {4.0, 4.0, 4.0, 4.0};
    system.upper = {1.0, 1.0, 1.0, 0.0};

    double rhsData[] = {1.0, 2.0, 3.0, 4.0};
    Vector rhs(4, rhsData);

    Vector y = solveTridiagonal(system, rhs);

    CHECK(4 * y[0] + 1 * y[1] == doctest::Approx(1.0).epsilon(1e-9));
    CHECK(1 * y[0] + 4 * y[1] + 1 * y[2] == doctest::Approx(2.0).epsilon(1e-9));
    CHECK(2 * y[1] + 4 * y[2] + 1 * y[3] == doctest::Approx(3.0).epsilon(1e-9));
    CHECK(1 * y[2] + 4 * y[3] == doctest::Approx(4.0).epsilon(1e-9));
}
