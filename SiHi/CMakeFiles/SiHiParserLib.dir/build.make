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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrew/Documents/projects/personal/LLCCEP/SiHi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrew/Documents/projects/personal/LLCCEP/SiHi

# Include any dependencies generated for this target.
include CMakeFiles/SiHiParserLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SiHiParserLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SiHiParserLib.dir/flags.make

SiHiParser.cpp: SiHi.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][SiHiParser] Building parser with bison 3.0.4"
	/usr/local/bin/bison -d -o /Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp /Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y

SiHiParser.hpp: SiHiParser.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate SiHiParser.hpp

CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o: CMakeFiles/SiHiParserLib.dir/flags.make
CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o: SiHiParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o -c /Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp

CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp > CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.i

CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp -o CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.s

CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.requires:

.PHONY : CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.requires

CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.provides: CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.requires
	$(MAKE) -f CMakeFiles/SiHiParserLib.dir/build.make CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.provides.build
.PHONY : CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.provides

CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.provides.build: CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o


# Object files for target SiHiParserLib
SiHiParserLib_OBJECTS = \
"CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o"

# External object files for target SiHiParserLib
SiHiParserLib_EXTERNAL_OBJECTS =

libSiHiParserLib.a: CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o
libSiHiParserLib.a: CMakeFiles/SiHiParserLib.dir/build.make
libSiHiParserLib.a: CMakeFiles/SiHiParserLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libSiHiParserLib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SiHiParserLib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SiHiParserLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SiHiParserLib.dir/build: libSiHiParserLib.a

.PHONY : CMakeFiles/SiHiParserLib.dir/build

CMakeFiles/SiHiParserLib.dir/requires: CMakeFiles/SiHiParserLib.dir/SiHiParser.cpp.o.requires

.PHONY : CMakeFiles/SiHiParserLib.dir/requires

CMakeFiles/SiHiParserLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SiHiParserLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SiHiParserLib.dir/clean

CMakeFiles/SiHiParserLib.dir/depend: SiHiParser.cpp
CMakeFiles/SiHiParserLib.dir/depend: SiHiParser.hpp
	cd /Users/andrew/Documents/projects/personal/LLCCEP/SiHi && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrew/Documents/projects/personal/LLCCEP/SiHi /Users/andrew/Documents/projects/personal/LLCCEP/SiHi /Users/andrew/Documents/projects/personal/LLCCEP/SiHi /Users/andrew/Documents/projects/personal/LLCCEP/SiHi /Users/andrew/Documents/projects/personal/LLCCEP/SiHi/CMakeFiles/SiHiParserLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SiHiParserLib.dir/depend

