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
include CMakeFiles/kb_driver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kb_driver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kb_driver.dir/flags.make

CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o: CMakeFiles/kb_driver.dir/flags.make
CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o: /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o -c /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp

CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp > CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.i

CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp -o CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.s

CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.requires:
.PHONY : CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.requires

CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.provides: CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.requires
	$(MAKE) -f CMakeFiles/kb_driver.dir/build.make CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.provides.build
.PHONY : CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.provides

CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.provides.build: CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o

# Object files for target kb_driver
kb_driver_OBJECTS = \
"CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o"

# External object files for target kb_driver
kb_driver_EXTERNAL_OBJECTS =

libkb_driver.a: CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o
libkb_driver.a: CMakeFiles/kb_driver.dir/build.make
libkb_driver.a: CMakeFiles/kb_driver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libkb_driver.a"
	$(CMAKE_COMMAND) -P CMakeFiles/kb_driver.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kb_driver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kb_driver.dir/build: libkb_driver.a
.PHONY : CMakeFiles/kb_driver.dir/build

CMakeFiles/kb_driver.dir/requires: CMakeFiles/kb_driver.dir/home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/drivers/kb/kb.cpp.o.requires
.PHONY : CMakeFiles/kb_driver.dir/requires

CMakeFiles/kb_driver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kb_driver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kb_driver.dir/clean

CMakeFiles/kb_driver.dir/depend:
	cd /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/CMakeFiles/kb_driver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kb_driver.dir/depend

