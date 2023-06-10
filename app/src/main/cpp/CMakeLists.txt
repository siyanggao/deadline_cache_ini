cmake_minimum_required(VERSION 3.18.1)

project("ini_app")

add_library(
        ini_app
        SHARED
        native-lib.cpp test.cpp simple_lru_cache_test.cpp deadline_cache_test.cpp
)

add_subdirectory(../../../../inilibrary/src/main/cpp ${PROJECT_BINARY_DIR}/ini)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries(
        ini_app

        ini
        ${log-lib}
)
