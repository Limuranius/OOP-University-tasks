# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Gleb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Gleb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Gleb\Desktop\5\OOP-University-tasks\5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/test.dir/depend.make
# Include the progress variables for this target.
include tests/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test.dir/flags.make

tests/CMakeFiles/test.dir/tests.cpp.obj: tests/CMakeFiles/test.dir/flags.make
tests/CMakeFiles/test.dir/tests.cpp.obj: tests/CMakeFiles/test.dir/includes_CXX.rsp
tests/CMakeFiles/test.dir/tests.cpp.obj: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test.dir/tests.cpp.obj"
	cd /d C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\tests && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test.dir\tests.cpp.obj -c C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\tests\tests.cpp

tests/CMakeFiles/test.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/tests.cpp.i"
	cd /d C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\tests && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\tests\tests.cpp > CMakeFiles\test.dir\tests.cpp.i

tests/CMakeFiles/test.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/tests.cpp.s"
	cd /d C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\tests && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\tests\tests.cpp -o CMakeFiles\test.dir\tests.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/tests.cpp.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

tests/test.exe: tests/CMakeFiles/test.dir/tests.cpp.obj
tests/test.exe: tests/CMakeFiles/test.dir/build.make
tests/test.exe: matrix/libmatrix.dll.a
tests/test.exe: lib/libgtestd.a
tests/test.exe: lib/libgtest_maind.a
tests/test.exe: lib/libgtestd.a
tests/test.exe: tests/CMakeFiles/test.dir/linklibs.rsp
tests/test.exe: tests/CMakeFiles/test.dir/objects1.rsp
tests/test.exe: tests/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test.exe"
	cd /d C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test.dir/build: tests/test.exe
.PHONY : tests/CMakeFiles/test.dir/build

tests/CMakeFiles/test.dir/clean:
	cd /d C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\tests && $(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean.cmake
.PHONY : tests/CMakeFiles/test.dir/clean

tests/CMakeFiles/test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Gleb\Desktop\5\OOP-University-tasks\5 C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\tests C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\tests C:\Users\Gleb\Desktop\5\OOP-University-tasks\5\cmake-build-debug\tests\CMakeFiles\test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test.dir/depend

