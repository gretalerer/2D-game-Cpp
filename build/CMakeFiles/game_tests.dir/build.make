# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build"

# Include any dependencies generated for this target.
include CMakeFiles/game_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_tests.dir/flags.make

CMakeFiles/game_tests.dir/tests/game_test.cpp.o: CMakeFiles/game_tests.dir/flags.make
CMakeFiles/game_tests.dir/tests/game_test.cpp.o: /Users/santiagofischel/Desktop/University/Programming\ 2/2D-game-priv/tests/game_test.cpp
CMakeFiles/game_tests.dir/tests/game_test.cpp.o: CMakeFiles/game_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game_tests.dir/tests/game_test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game_tests.dir/tests/game_test.cpp.o -MF CMakeFiles/game_tests.dir/tests/game_test.cpp.o.d -o CMakeFiles/game_tests.dir/tests/game_test.cpp.o -c "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/tests/game_test.cpp"

CMakeFiles/game_tests.dir/tests/game_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game_tests.dir/tests/game_test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/tests/game_test.cpp" > CMakeFiles/game_tests.dir/tests/game_test.cpp.i

CMakeFiles/game_tests.dir/tests/game_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game_tests.dir/tests/game_test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/tests/game_test.cpp" -o CMakeFiles/game_tests.dir/tests/game_test.cpp.s

CMakeFiles/game_tests.dir/src/game.cpp.o: CMakeFiles/game_tests.dir/flags.make
CMakeFiles/game_tests.dir/src/game.cpp.o: /Users/santiagofischel/Desktop/University/Programming\ 2/2D-game-priv/src/game.cpp
CMakeFiles/game_tests.dir/src/game.cpp.o: CMakeFiles/game_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game_tests.dir/src/game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game_tests.dir/src/game.cpp.o -MF CMakeFiles/game_tests.dir/src/game.cpp.o.d -o CMakeFiles/game_tests.dir/src/game.cpp.o -c "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/src/game.cpp"

CMakeFiles/game_tests.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game_tests.dir/src/game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/src/game.cpp" > CMakeFiles/game_tests.dir/src/game.cpp.i

CMakeFiles/game_tests.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game_tests.dir/src/game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/src/game.cpp" -o CMakeFiles/game_tests.dir/src/game.cpp.s

CMakeFiles/game_tests.dir/src/move.cpp.o: CMakeFiles/game_tests.dir/flags.make
CMakeFiles/game_tests.dir/src/move.cpp.o: /Users/santiagofischel/Desktop/University/Programming\ 2/2D-game-priv/src/move.cpp
CMakeFiles/game_tests.dir/src/move.cpp.o: CMakeFiles/game_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game_tests.dir/src/move.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game_tests.dir/src/move.cpp.o -MF CMakeFiles/game_tests.dir/src/move.cpp.o.d -o CMakeFiles/game_tests.dir/src/move.cpp.o -c "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/src/move.cpp"

CMakeFiles/game_tests.dir/src/move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game_tests.dir/src/move.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/src/move.cpp" > CMakeFiles/game_tests.dir/src/move.cpp.i

CMakeFiles/game_tests.dir/src/move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game_tests.dir/src/move.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/src/move.cpp" -o CMakeFiles/game_tests.dir/src/move.cpp.s

# Object files for target game_tests
game_tests_OBJECTS = \
"CMakeFiles/game_tests.dir/tests/game_test.cpp.o" \
"CMakeFiles/game_tests.dir/src/game.cpp.o" \
"CMakeFiles/game_tests.dir/src/move.cpp.o"

# External object files for target game_tests
game_tests_EXTERNAL_OBJECTS =

game_tests: CMakeFiles/game_tests.dir/tests/game_test.cpp.o
game_tests: CMakeFiles/game_tests.dir/src/game.cpp.o
game_tests: CMakeFiles/game_tests.dir/src/move.cpp.o
game_tests: CMakeFiles/game_tests.dir/build.make
game_tests: lib/libgtest_main.a
game_tests: /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-graphics.2.6.1.dylib
game_tests: /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-window.2.6.1.dylib
game_tests: /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-system.2.6.1.dylib
game_tests: lib/libgtest.a
game_tests: CMakeFiles/game_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable game_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_tests.dir/build: game_tests
.PHONY : CMakeFiles/game_tests.dir/build

CMakeFiles/game_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_tests.dir/clean

CMakeFiles/game_tests.dir/depend:
	cd "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv" "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv" "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build" "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build" "/Users/santiagofischel/Desktop/University/Programming 2/2D-game-priv/build/CMakeFiles/game_tests.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/game_tests.dir/depend

