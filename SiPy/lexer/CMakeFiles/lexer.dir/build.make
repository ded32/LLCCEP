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
CMAKE_SOURCE_DIR = /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer

# Include any dependencies generated for this target.
include CMakeFiles/lexer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lexer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lexer.dir/flags.make

CMakeFiles/lexer.dir/lexer.cpp.o: CMakeFiles/lexer.dir/flags.make
CMakeFiles/lexer.dir/lexer.cpp.o: lexer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew/Documents/projects/LLCCEP/SiPy/lexer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lexer.dir/lexer.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lexer.dir/lexer.cpp.o -c /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer/lexer.cpp

CMakeFiles/lexer.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lexer.dir/lexer.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer/lexer.cpp > CMakeFiles/lexer.dir/lexer.cpp.i

CMakeFiles/lexer.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lexer.dir/lexer.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer/lexer.cpp -o CMakeFiles/lexer.dir/lexer.cpp.s

CMakeFiles/lexer.dir/lexer.cpp.o.requires:

.PHONY : CMakeFiles/lexer.dir/lexer.cpp.o.requires

CMakeFiles/lexer.dir/lexer.cpp.o.provides: CMakeFiles/lexer.dir/lexer.cpp.o.requires
	$(MAKE) -f CMakeFiles/lexer.dir/build.make CMakeFiles/lexer.dir/lexer.cpp.o.provides.build
.PHONY : CMakeFiles/lexer.dir/lexer.cpp.o.provides

CMakeFiles/lexer.dir/lexer.cpp.o.provides.build: CMakeFiles/lexer.dir/lexer.cpp.o


# Object files for target lexer
lexer_OBJECTS = \
"CMakeFiles/lexer.dir/lexer.cpp.o"

# External object files for target lexer
lexer_EXTERNAL_OBJECTS =

liblexer.a: CMakeFiles/lexer.dir/lexer.cpp.o
liblexer.a: CMakeFiles/lexer.dir/build.make
liblexer.a: CMakeFiles/lexer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew/Documents/projects/LLCCEP/SiPy/lexer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblexer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/lexer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lexer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lexer.dir/build: liblexer.a

.PHONY : CMakeFiles/lexer.dir/build

CMakeFiles/lexer.dir/requires: CMakeFiles/lexer.dir/lexer.cpp.o.requires

.PHONY : CMakeFiles/lexer.dir/requires

CMakeFiles/lexer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lexer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lexer.dir/clean

CMakeFiles/lexer.dir/depend:
	cd /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer /Users/andrew/Documents/projects/LLCCEP/SiPy/lexer/CMakeFiles/lexer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lexer.dir/depend

