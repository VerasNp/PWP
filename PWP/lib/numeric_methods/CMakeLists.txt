add_library(numeric_methods
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Derivate.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/eigenvalue_problems/PowerMethod.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/matrices_factorization/LUDecomposition.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/linear_systems/direct_methods/GaussElimination.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/transformations/Householder.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/matrices_factorization/QRDecomposition.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/linear_systems/direct_methods/LUSolver.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/linear_systems/direct_methods/TridiagonalSolver.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/boundary_value_problems/FiniteDifferenceMethod.cpp"
)

target_sources(numeric_methods
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/DerivateBase.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/stencil/Stencil.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/stencil/forward/ForwardStencil.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Derivate.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/eigenvalue_problems/PowerMethod.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/matrices_factorization/LUDecomposition.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/linear_systems/ILinearSystem.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/linear_systems/direct_methods/LUSolver.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/linear_systems/direct_methods/GaussElimination.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/transformations/Householder.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/matrices_factorization/QRDecomposition.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/linear_systems/direct_methods/TridiagonalSolver.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/boundary_value_problems/LinearBVP.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/boundary_value_problems/FiniteDifferenceMethod.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/QuadratureStencil.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/Integrate.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/NewtonCotes.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/GaussRule.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/gauss/GaussLegendre.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/gauss/GaussHermite.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/gauss/GaussLaguerre.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/gauss/GaussChebyshev.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/integrate/ExponentialChange.hpp"
)

target_include_directories(numeric_methods
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(numeric_methods PUBLIC core)
