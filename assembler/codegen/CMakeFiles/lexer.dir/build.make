# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen

# Include any dependencies generated for this target.
include CMakeFiles/lexer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lexer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lexer.dir/flags.make

CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o: CMakeFiles/lexer.dir/flags.make
CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o: /home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o -c /home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp

CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp > CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.i

CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp -o CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.s

CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.requires:

.PHONY : CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.requires

CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.provides: CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/lexer.dir/build.make CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.provides.build
.PHONY : CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.provides

CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.provides.build: CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o


# Object files for target lexer
lexer_OBJECTS = \
"CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o"

# External object files for target lexer
lexer_EXTERNAL_OBJECTS =

liblexer.a: CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o
liblexer.a: CMakeFiles/lexer.dir/build.make
liblexer.a: CMakeFiles/lexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblexer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lexer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lexer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lexer.dir/build: liblexer.a

.PHONY : CMakeFiles/lexer.dir/build

CMakeFiles/lexer.dir/requires: CMakeFiles/lexer.dir/home/andrew/Desktop/personal/projects/LLCCEP/assembler/lexer/lexer.cpp.o.requires

.PHONY : CMakeFiles/lexer.dir/requires

CMakeFiles/lexer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lexer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lexer.dir/clean

CMakeFiles/lexer.dir/depend:
	cd /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen /home/andrew/Desktop/personal/projects/LLCCEP/assembler/codegen/CMakeFiles/lexer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lexer.dir/depend

