# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/Documents/personal/projects/LLCCEP/JIT/program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/Documents/personal/projects/LLCCEP/JIT/program

# Include any dependencies generated for this target.
include CMakeFiles/emitter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/emitter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/emitter.dir/flags.make

CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o: CMakeFiles/emitter.dir/flags.make
CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o: /home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/Documents/personal/projects/LLCCEP/JIT/program/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o -c /home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp

CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp > CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.i

CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp -o CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.s

CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.requires:
.PHONY : CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.requires

CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.provides: CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.requires
	$(MAKE) -f CMakeFiles/emitter.dir/build.make CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.provides.build
.PHONY : CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.provides

CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.provides.build: CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o

# Object files for target emitter
emitter_OBJECTS = \
"CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o"

# External object files for target emitter
emitter_EXTERNAL_OBJECTS =

libemitter.a: CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o
libemitter.a: CMakeFiles/emitter.dir/build.make
libemitter.a: CMakeFiles/emitter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libemitter.a"
	$(CMAKE_COMMAND) -P CMakeFiles/emitter.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/emitter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/emitter.dir/build: libemitter.a
.PHONY : CMakeFiles/emitter.dir/build

CMakeFiles/emitter.dir/requires: CMakeFiles/emitter.dir/home/andrew/Documents/personal/projects/LLCCEP/JIT/emitter/emitter.cpp.o.requires
.PHONY : CMakeFiles/emitter.dir/requires

CMakeFiles/emitter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/emitter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/emitter.dir/clean

CMakeFiles/emitter.dir/depend:
	cd /home/andrew/Documents/personal/projects/LLCCEP/JIT/program && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/Documents/personal/projects/LLCCEP/JIT/program /home/andrew/Documents/personal/projects/LLCCEP/JIT/program /home/andrew/Documents/personal/projects/LLCCEP/JIT/program /home/andrew/Documents/personal/projects/LLCCEP/JIT/program /home/andrew/Documents/personal/projects/LLCCEP/JIT/program/CMakeFiles/emitter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/emitter.dir/depend

