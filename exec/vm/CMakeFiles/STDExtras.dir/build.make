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
CMAKE_SOURCE_DIR = /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm

# Include any dependencies generated for this target.
include CMakeFiles/STDExtras.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/STDExtras.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/STDExtras.dir/flags.make

CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o: CMakeFiles/STDExtras.dir/flags.make
CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o: /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o -c /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp

CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp > CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.i

CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp -o CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.s

CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.requires:
.PHONY : CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.requires

CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.provides: CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.requires
	$(MAKE) -f CMakeFiles/STDExtras.dir/build.make CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.provides.build
.PHONY : CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.provides

CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.provides.build: CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o

# Object files for target STDExtras
STDExtras_OBJECTS = \
"CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o"

# External object files for target STDExtras
STDExtras_EXTERNAL_OBJECTS =

libSTDExtras.a: CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o
libSTDExtras.a: CMakeFiles/STDExtras.dir/build.make
libSTDExtras.a: CMakeFiles/STDExtras.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libSTDExtras.a"
	$(CMAKE_COMMAND) -P CMakeFiles/STDExtras.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/STDExtras.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/STDExtras.dir/build: libSTDExtras.a
.PHONY : CMakeFiles/STDExtras.dir/build

CMakeFiles/STDExtras.dir/requires: CMakeFiles/STDExtras.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/lib/STDExtras.cpp.o.requires
.PHONY : CMakeFiles/STDExtras.dir/requires

CMakeFiles/STDExtras.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/STDExtras.dir/cmake_clean.cmake
.PHONY : CMakeFiles/STDExtras.dir/clean

CMakeFiles/STDExtras.dir/depend:
	cd /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/CMakeFiles/STDExtras.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/STDExtras.dir/depend

