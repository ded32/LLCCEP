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
include CMakeFiles/VM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VM.dir/flags.make

CMakeFiles/VM.dir/main.cpp.o: CMakeFiles/VM.dir/flags.make
CMakeFiles/VM.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/VM.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/VM.dir/main.cpp.o -c /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/main.cpp

CMakeFiles/VM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VM.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/main.cpp > CMakeFiles/VM.dir/main.cpp.i

CMakeFiles/VM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VM.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/main.cpp -o CMakeFiles/VM.dir/main.cpp.s

CMakeFiles/VM.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/VM.dir/main.cpp.o.requires

CMakeFiles/VM.dir/main.cpp.o.provides: CMakeFiles/VM.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/VM.dir/build.make CMakeFiles/VM.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/VM.dir/main.cpp.o.provides

CMakeFiles/VM.dir/main.cpp.o.provides.build: CMakeFiles/VM.dir/main.cpp.o

# Object files for target VM
VM_OBJECTS = \
"CMakeFiles/VM.dir/main.cpp.o"

# External object files for target VM
VM_EXTERNAL_OBJECTS =

VM: CMakeFiles/VM.dir/main.cpp.o
VM: CMakeFiles/VM.dir/build.make
VM: libSTDExtras.a
VM: libconf.a
VM: libsetup.a
VM: libsoftcore.a
VM: libprog.a
VM: libdisplay_driver.a
VM: libhdd_driver.a
VM: libkb_driver.a
VM: libmouse_driver.a
VM: libram_driver.a
VM: CMakeFiles/VM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable VM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VM.dir/build: VM
.PHONY : CMakeFiles/VM.dir/build

CMakeFiles/VM.dir/requires: CMakeFiles/VM.dir/main.cpp.o.requires
.PHONY : CMakeFiles/VM.dir/requires

CMakeFiles/VM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VM.dir/clean

CMakeFiles/VM.dir/depend:
	cd /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm /home/andrew/shared/Home/Documents/projects/personal/LLCCEP/exec/vm/CMakeFiles/VM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VM.dir/depend

