# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zloadmin/projects/cleanLogo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zloadmin/projects/cleanLogo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cleanLogo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cleanLogo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cleanLogo.dir/flags.make

CMakeFiles/cleanLogo.dir/main.cpp.o: CMakeFiles/cleanLogo.dir/flags.make
CMakeFiles/cleanLogo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zloadmin/projects/cleanLogo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cleanLogo.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cleanLogo.dir/main.cpp.o -c /Users/zloadmin/projects/cleanLogo/main.cpp

CMakeFiles/cleanLogo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cleanLogo.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zloadmin/projects/cleanLogo/main.cpp > CMakeFiles/cleanLogo.dir/main.cpp.i

CMakeFiles/cleanLogo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cleanLogo.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zloadmin/projects/cleanLogo/main.cpp -o CMakeFiles/cleanLogo.dir/main.cpp.s

# Object files for target cleanLogo
cleanLogo_OBJECTS = \
"CMakeFiles/cleanLogo.dir/main.cpp.o"

# External object files for target cleanLogo
cleanLogo_EXTERNAL_OBJECTS =

cleanLogo: CMakeFiles/cleanLogo.dir/main.cpp.o
cleanLogo: CMakeFiles/cleanLogo.dir/build.make
cleanLogo: CMakeFiles/cleanLogo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zloadmin/projects/cleanLogo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cleanLogo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cleanLogo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cleanLogo.dir/build: cleanLogo

.PHONY : CMakeFiles/cleanLogo.dir/build

CMakeFiles/cleanLogo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cleanLogo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cleanLogo.dir/clean

CMakeFiles/cleanLogo.dir/depend:
	cd /Users/zloadmin/projects/cleanLogo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zloadmin/projects/cleanLogo /Users/zloadmin/projects/cleanLogo /Users/zloadmin/projects/cleanLogo/cmake-build-debug /Users/zloadmin/projects/cleanLogo/cmake-build-debug /Users/zloadmin/projects/cleanLogo/cmake-build-debug/CMakeFiles/cleanLogo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cleanLogo.dir/depend

