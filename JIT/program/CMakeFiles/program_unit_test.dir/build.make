# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program

# Include any dependencies generated for this target.
include CMakeFiles/program_unit_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/program_unit_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/program_unit_test.dir/flags.make

CMakeFiles/program_unit_test.dir/test.cpp.o: CMakeFiles/program_unit_test.dir/flags.make
CMakeFiles/program_unit_test.dir/test.cpp.o: test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew/Documents/projects/personal/LLCCEP/JIT/program/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/program_unit_test.dir/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/program_unit_test.dir/test.cpp.o -c /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program/test.cpp

CMakeFiles/program_unit_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program_unit_test.dir/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program/test.cpp > CMakeFiles/program_unit_test.dir/test.cpp.i

CMakeFiles/program_unit_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program_unit_test.dir/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program/test.cpp -o CMakeFiles/program_unit_test.dir/test.cpp.s

CMakeFiles/program_unit_test.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/program_unit_test.dir/test.cpp.o.requires

CMakeFiles/program_unit_test.dir/test.cpp.o.provides: CMakeFiles/program_unit_test.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/program_unit_test.dir/build.make CMakeFiles/program_unit_test.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/program_unit_test.dir/test.cpp.o.provides

CMakeFiles/program_unit_test.dir/test.cpp.o.provides.build: CMakeFiles/program_unit_test.dir/test.cpp.o


# Object files for target program_unit_test
program_unit_test_OBJECTS = \
"CMakeFiles/program_unit_test.dir/test.cpp.o"

# External object files for target program_unit_test
program_unit_test_EXTERNAL_OBJECTS =

program_unit_test: CMakeFiles/program_unit_test.dir/test.cpp.o
program_unit_test: CMakeFiles/program_unit_test.dir/build.make
program_unit_test: libemitter.a
program_unit_test: libstartup.a
program_unit_test: libprogram.a
program_unit_test: libstack_protector.a
program_unit_test: libemitter.a
program_unit_test: CMakeFiles/program_unit_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew/Documents/projects/personal/LLCCEP/JIT/program/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable program_unit_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/program_unit_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/program_unit_test.dir/build: program_unit_test

.PHONY : CMakeFiles/program_unit_test.dir/build

CMakeFiles/program_unit_test.dir/requires: CMakeFiles/program_unit_test.dir/test.cpp.o.requires

.PHONY : CMakeFiles/program_unit_test.dir/requires

CMakeFiles/program_unit_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/program_unit_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/program_unit_test.dir/clean

CMakeFiles/program_unit_test.dir/depend:
	cd /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program /Users/andrew/Documents/projects/personal/LLCCEP/JIT/program/CMakeFiles/program_unit_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/program_unit_test.dir/depend

