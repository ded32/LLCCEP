# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu

# Include any dependencies generated for this target.
include CMakeFiles/window.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/window.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/window.dir/flags.make

CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o: CMakeFiles/window.dir/flags.make
CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o: /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o -c /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp

CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp > CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.i

CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp -o CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.s

CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.requires:
.PHONY : CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.requires

CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.provides: CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.requires
	$(MAKE) -f CMakeFiles/window.dir/build.make CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.provides.build
.PHONY : CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.provides

CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.provides.build: CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o

# Object files for target window
window_OBJECTS = \
"CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o"

# External object files for target window
window_EXTERNAL_OBJECTS =

libwindow.a: CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o
libwindow.a: CMakeFiles/window.dir/build.make
libwindow.a: CMakeFiles/window.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libwindow.a"
	$(CMAKE_COMMAND) -P CMakeFiles/window.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/window.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/window.dir/build: libwindow.a
.PHONY : CMakeFiles/window.dir/build

CMakeFiles/window.dir/requires: CMakeFiles/window.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/window/window.cpp.o.requires
.PHONY : CMakeFiles/window.dir/requires

CMakeFiles/window.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/window.dir/cmake_clean.cmake
.PHONY : CMakeFiles/window.dir/clean

CMakeFiles/window.dir/depend:
	cd /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/emu/CMakeFiles/window.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/window.dir/depend

