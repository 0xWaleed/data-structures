project(${PROJECT_NAME}_demo CXX)

add_executable(${PROJECT_NAME}_stack stack.cpp)
add_executable(${PROJECT_NAME}_linklist linklist.cpp)
add_executable(${PROJECT_NAME}_queue queue.cpp)

target_link_libraries(${PROJECT_NAME}_stack PRIVATE ${CMAKE_PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_linklist PRIVATE ${CMAKE_PROJECT_NAME})
target_link_libraries(${PROJECT_NAME}_queue PRIVATE ${CMAKE_PROJECT_NAME})
