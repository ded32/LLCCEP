# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis

# Include any dependencies generated for this target.
include CMakeFiles/analysis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/analysis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/analysis.dir/flags.make

CMakeFiles/analysis.dir/analysis.cpp.o: CMakeFiles/analysis.dir/flags.make
CMakeFiles/analysis.dir/analysis.cpp.o: analysis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/analysis.dir/analysis.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/analysis.dir/analysis.cpp.o -c /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis/analysis.cpp

CMakeFiles/analysis.dir/analysis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analysis.dir/analysis.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis/analysis.cpp > CMakeFiles/analysis.dir/analysis.cpp.i

CMakeFiles/analysis.dir/analysis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analysis.dir/analysis.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis/analysis.cpp -o CMakeFiles/analysis.dir/analysis.cpp.s

CMakeFiles/analysis.dir/analysis.cpp.o.requires:

.PHONY : CMakeFiles/analysis.dir/analysis.cpp.o.requires

CMakeFiles/analysis.dir/analysis.cpp.o.provides: CMakeFiles/analysis.dir/analysis.cpp.o.requires
	$(MAKE) -f CMakeFiles/analysis.dir/build.make CMakeFiles/analysis.dir/analysis.cpp.o.provides.build
.PHONY : CMakeFiles/analysis.dir/analysis.cpp.o.provides

CMakeFiles/analysis.dir/analysis.cpp.o.provides.build: CMakeFiles/analysis.dir/analysis.cpp.o


# Object files for target analysis
analysis_OBJECTS = \
"CMakeFiles/analysis.dir/analysis.cpp.o"

# External object files for target analysis
analysis_EXTERNAL_OBJECTS =

libanalysis.a: CMakeFiles/analysis.dir/analysis.cpp.o
libanalysis.a: CMakeFiles/analysis.dir/build.make
libanalysis.a: CMakeFiles/analysis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libanalysis.a"
	$(CMAKE_COMMAND) -P CMakeFiles/analysis.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/analysis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/analysis.dir/build: libanalysis.a

.PHONY : CMakeFiles/analysis.dir/build

CMakeFiles/analysis.dir/requires: CMakeFiles/analysis.dir/analysis.cpp.o.requires

.PHONY : CMakeFiles/analysis.dir/requires

CMakeFiles/analysis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/analysis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/analysis.dir/clean

CMakeFiles/analysis.dir/depend:
	cd /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis /home/andrew/Documents/personal/projects/LLCCEP/assembler/analysis/CMakeFiles/analysis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/analysis.dir/depend

