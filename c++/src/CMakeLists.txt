project(${PROJECT_NAME})

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME} INTERFACE
               include/Stack.hpp
               include/SinglyNode.hpp
               include/LinkedList.hpp
               include/Queue.hpp)

target_include_directories(${PROJECT_NAME} INTERFACE include)

