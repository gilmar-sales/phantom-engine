cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(phantom-engine)

find_package(OpenGL REQUIRED)

include_directories(
    "phantom/src"
    "phantom/libraries/spdlog/include"
    "phantom/libraries/glad/include"
    "phantom/libraries/glfw/include"
    "phantom/libraries/imgui"
    "phantom/libraries/glm"
)

add_subdirectory("phantom")
add_subdirectory("editor")

