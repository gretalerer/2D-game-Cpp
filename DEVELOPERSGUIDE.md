# StellarStriker Developer's Guide

This guide is intended for software developers interested in contributing to the StellarStriker project. It covers the architecture, setup, contribution guidelines, and other relevant information.

## Project Overview
StellarStriker is a 2D space shooter game built using SFML. The game features a player-controlled spaceship that can move and shoot, and enemy aliens that spawn randomly on the screen.

## Environment Setup
To set up your development environment for StellarStriker, you will need:

- SFML installed on your system.
- A C++14 compliant compiler.
- CMake for building the project.

## Building the Project
To build the game from the source:

1. Clone the repository to your local machine.
2. Navigate to the cloned repository.
3. Create a new sub-folder called `build`
4. Run `cmake ..` in the terminal to generate the Makefile.
5. Run `make` to build the executable.

## Codebase Structure
The codebase is organized into several main components:

- `src/`: Contains the game's source code, including the main game loop and event handling.
- `include/`: Header files for the game's classes and functions.
- `tests/`: Unit tests for the game's functionality.

## Contributing
We welcome contributions! If you'd like to contribute, please:

1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Write clean, commented, and tested code.
4. Submit a pull request with a clear description of your changes.

## Testing
To ensure the quality of the game, please write unit tests for new code using Google Test framework included in the project.

## Documentation
All new code should be well-documented with comments explaining the functionality and any important considerations.

## Support
For questions or support, please open an issue on the GitHub repository or contact the project maintainers.

Thank you for contributing to StellarStriker!
