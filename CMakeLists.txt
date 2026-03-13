cmake_minimum_required(VERSION 3.20)
project(Snake CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_LIBCPP_DISABLE_AVAILABILITY")
endif()

FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.2
        GIT_SHALLOW TRUE
)

set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)

if(APPLE)
    set(SFML_OS_MACOSX TRUE CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(sfml)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

add_executable(Snake ${SOURCES} ${HEADERS}
        tests/test_game_entity.cpp)
target_include_directories(Snake PRIVATE include)

target_link_libraries(Snake PRIVATE
        sfml-graphics
        sfml-window
        sfml-system
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/
        FILES_MATCHING PATTERN "*.ttf"
)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST_SOURCES src/*.cpp)
list(REMOVE_ITEM TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_executable(SNAKEGAME_TESTS
        tests/test_main.cpp
        tests/test_snake.cpp
        tests/test_food.cpp
        tests/test_Board.cpp
        tests/test_game_entity.cpp
        ${TEST_SOURCES}
        tests/test_foodgenerator.cpp
        tests/test_segment.cpp
        tests/test_renderer.cpp
)

target_include_directories(SNAKEGAME_TESTS PRIVATE include)
target_link_libraries(SNAKEGAME_TESTS PRIVATE
        gtest_main
        sfml-graphics
        sfml-window
        sfml-system
)

include(GoogleTest)
gtest_discover_tests(SNAKEGAME_TESTS)