cmake_minimum_required(VERSION 3.20)
project(Snake CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW TRUE
)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

FetchContent_MakeAvailable(sfml)

add_executable(Snake)
add_subdirectory(src)
add_subdirectory(include)

target_include_directories(Snake PRIVATE include)

target_link_libraries(Snake PRIVATE sfml-graphics sfml-window sfml-system)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/
        FILES_MATCHING PATTERN "*.ttf"
)
