
project(${PROJECT_NAME} LANGUAGES C)

set(CMAKE_C_STANDARD 11)

Include(FetchContent)

FetchContent_Declare(
        clist
        GIT_REPOSITORY https://github.com/BISOON/clist.git)

FetchContent_MakeAvailable(clist)

list(APPEND _SOURCES
     include/stack.h
     stack.c
     include/link-list.h
     link-list.c
     )

add_library(${PROJECT_NAME} ${_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_link_libraries(${PROJECT_NAME} PUBLIC clist)
