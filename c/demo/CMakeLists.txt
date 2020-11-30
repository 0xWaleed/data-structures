project(${PROJECT_NAME}_demo)

list(APPEND _PROJECTS stack linklist)


foreach (project ${_PROJECTS})
    add_executable(${PROJECT_NAME}_${project} ${project}.c)
    target_link_libraries(${PROJECT_NAME}_${project} PRIVATE ${CMAKE_PROJECT_NAME})
endforeach ()
