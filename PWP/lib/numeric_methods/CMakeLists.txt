add_library(numeric_methods
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Derivate.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/eigenvalue_problems/PowerMethod.cpp"
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
)

target_include_directories(numeric_methods
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(numeric_methods PUBLIC core)
