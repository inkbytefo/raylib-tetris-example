cmake_minimum_required(VERSION 3.20)

project("MyGame" LANGUAGES C CXX)

# ====================== RAYLIB FETCHCONTENT ======================
include(FetchContent)

# If the build environment cannot verify TLS certificates (common in some
# bundled CMake/cURL setups), disable TLS verification for FetchContent
# downloads so the raylib archive can be fetched. This mirrors setting the
# environment variable CMAKE_TLS_VERIFY=0 before running CMake.
set(ENV{CMAKE_TLS_VERIFY} "0")

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.5.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)
# ================================================================

add_subdirectory("MyGame")