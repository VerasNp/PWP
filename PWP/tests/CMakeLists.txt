set(TestsToRun
    "${CMAKE_CURRENT_SOURCE_DIR}/numeric_methods/Forward.test.cpp"
)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)
    message(${TName})
    add_executable(${TName} ${test} "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    target_compile_features(${TName} PRIVATE cxx_std_20)
    target_link_libraries(${TName} PRIVATE Doctest PWP numeric_methods)
    add_test(NAME ${TName} COMMAND ${TName})
endforeach()
