cmake_minimum_required(VERSION 3.17)

project(data-structure LANGUAGES C)

add_subdirectory(src)

enable_testing()

add_subdirectory(tests)

add_subdirectory(demo)
