add_library(numeric_methods
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/IDerivate.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/IDerivateCreator.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/DerivateBase.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/stencil/Stencil.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Backward.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Backward.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Central.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Central.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Forward.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/Forward.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/ForwardCreator.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/derivate/ForwardCreator.cpp"
)

target_include_directories(numeric_methods PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/derivate")
