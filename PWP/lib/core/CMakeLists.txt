add_library(core
    "${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector.cpp"
)

target_sources(core
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}"
    FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/Matrix.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/utils.hpp"
)

target_include_directories(core
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)
