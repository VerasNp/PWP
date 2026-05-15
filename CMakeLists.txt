cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(PWP LANGUAGES CXX)

enable_testing()

add_subdirectory(PWP)
