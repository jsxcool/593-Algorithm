# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Bitvec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bitvec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bitvec.dir/flags.make

CMakeFiles/Bitvec.dir/main.cpp.o: CMakeFiles/Bitvec.dir/flags.make
CMakeFiles/Bitvec.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Bitvec.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Bitvec.dir/main.cpp.o -c /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/main.cpp

CMakeFiles/Bitvec.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Bitvec.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/main.cpp > CMakeFiles/Bitvec.dir/main.cpp.i

CMakeFiles/Bitvec.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Bitvec.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/main.cpp -o CMakeFiles/Bitvec.dir/main.cpp.s

CMakeFiles/Bitvec.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Bitvec.dir/main.cpp.o.requires

CMakeFiles/Bitvec.dir/main.cpp.o.provides: CMakeFiles/Bitvec.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Bitvec.dir/build.make CMakeFiles/Bitvec.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Bitvec.dir/main.cpp.o.provides

CMakeFiles/Bitvec.dir/main.cpp.o.provides.build: CMakeFiles/Bitvec.dir/main.cpp.o


# Object files for target Bitvec
Bitvec_OBJECTS = \
"CMakeFiles/Bitvec.dir/main.cpp.o"

# External object files for target Bitvec
Bitvec_EXTERNAL_OBJECTS =

Bitvec: CMakeFiles/Bitvec.dir/main.cpp.o
Bitvec: CMakeFiles/Bitvec.dir/build.make
Bitvec: CMakeFiles/Bitvec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Bitvec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bitvec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bitvec.dir/build: Bitvec

.PHONY : CMakeFiles/Bitvec.dir/build

CMakeFiles/Bitvec.dir/requires: CMakeFiles/Bitvec.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Bitvec.dir/requires

CMakeFiles/Bitvec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bitvec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bitvec.dir/clean

CMakeFiles/Bitvec.dir/depend:
	cd /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/cmake-build-debug /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/cmake-build-debug /Users/shangxingjiang/Desktop/593-Algorithm/Bitvec/cmake-build-debug/CMakeFiles/Bitvec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bitvec.dir/depend

