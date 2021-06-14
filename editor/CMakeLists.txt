file(GLOB_RECURSE EDITOR_SRC
    "src/*.cpp"
)

add_executable(editor
    ${EDITOR_SRC}
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/asdasdd) 

target_link_libraries(editor
    phantom
    imgui
    glfw
    glad
    spdlog
)