cmake_minimum_required(VERSION 3.25)
project(2D_game_assignment)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

include_directories(include)

configure_file(resources/background.png ${CMAKE_CURRENT_BINARY_DIR}/resources/background.png COPYONLY)
configure_file(resources/pacman.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman.png COPYONLY)
configure_file(resources/ghost.png ${CMAKE_CURRENT_BINARY_DIR}/resources/ghost.png COPYONLY)
configure_file(resources/pacman-explosion.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman-explosion.png COPYONLY)


add_executable(2D_game_assignment
        src/main.cpp
        src/game.cpp
        src/game.cpp
        src/move.cpp
        src/bullet.cpp
        include/move.h
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Google Test
add_subdirectory(extern/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Test executable
add_executable(game_tests
        tests/game_test.cpp
        src/game.cpp
        src/move.cpp
        src/bullet.cpp
)

# Link SFML libraries to the test executable
target_link_libraries(game_tests gtest_main sfml-graphics sfml-window sfml-system)
