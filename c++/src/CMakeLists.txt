
add_library(${PROJECT_NAME}
            include/Stack.test.hpp
                Stack.cpp
            )

target_include_directories(${PROJECT_NAME} PUBLIC include)
