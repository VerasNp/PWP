add_subdirectory(lib)

add_library(PWP INTERFACE)
target_link_libraries(PWP INTERFACE numeric_methods)

add_library(Doctest INTERFACE)
target_include_directories(Doctest INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/third_party/doctest")
add_subdirectory(tests)
