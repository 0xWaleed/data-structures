
project(${PROJECT_NAME} LANGUAGES C)

set(CMAKE_C_STANDARD 11)

list(APPEND _SOURCES
     include/stack.h
     stack.c
     )

add_library(${PROJECT_NAME} ${_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
