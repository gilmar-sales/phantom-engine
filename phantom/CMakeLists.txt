

file(GLOB_RECURSE PHANTOM_SRC
    "src/*.cpp"
)

add_library(phantom
    ${PHANTOM_SRC}
)

add_subdirectory("libraries")


