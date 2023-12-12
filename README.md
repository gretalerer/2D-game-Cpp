# StellarStriker

## Installation Guidelines
To build and run the 2D Game Assignment, you will need to have CMake installed and configured for your system.

1. Clone the repository to your local machine.
2. Navigate to the cloned directory.
3. Run `cmake .` in the terminal to generate the Makefile.
4. Run `make` to build the executable.

## Dependencies
- SFML 2.6 or higher
- C++14 compliant compiler
- Google Test (included as a submodule)

Ensure that SFML is installed on your system. On macOS, you can install SFML using Homebrew with the following command:

`brew install sfml`


## Environment
The game is currently set up to run in an environment with the following configurations:
- SFML_DIR is expected to be at `/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML`
- CMake version 3.25 or higher

If your SFML directory differs, update the `SFML_DIR` variable in the `CMakeLists.txt`.

## Running Tests
To run the provided tests, execute the following command after building the project:
`./game_tests`



