

file(GLOB_RECURSE PHANTOM_SRC
    "src/*.cpp"
    "src/*.h"
)

add_library(phantom
    ${PHANTOM_SRC}
)

add_subdirectory("libraries")


