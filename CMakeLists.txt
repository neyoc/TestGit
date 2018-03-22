cmake_minimum_required(VERSION 2.8)

project(opengl)
add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(
    opengl
    glut
    GL
)
