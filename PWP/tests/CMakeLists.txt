set(TestsToRun
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Matrix.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Stencil.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Forward.test.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Backward.test.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/PowerMethod.test.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/LUDecomposition.test.cpp"
    # "${CMAKE_CURRENT_SOURCE_DIR}/LUSolver.test.cpp"
)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)
    string(REPLACE ".test" "" TName ${TName})
    add_executable(${TName} ${test} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    target_compile_features(${TName} PRIVATE cxx_std_20)
    target_link_libraries(${TName} PRIVATE Doctest PWP numeric_methods core)
    add_test(NAME ${TName} COMMAND ${TName})
endforeach()
