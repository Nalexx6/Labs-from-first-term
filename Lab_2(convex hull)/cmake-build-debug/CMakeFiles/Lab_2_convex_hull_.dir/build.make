# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab_2_convex_hull_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_2_convex_hull_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_2_convex_hull_.dir/flags.make

CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.obj: CMakeFiles/Lab_2_convex_hull_.dir/flags.make
CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_2_convex_hull_.dir\main.cpp.obj -c "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\main.cpp"

CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\main.cpp" > CMakeFiles\Lab_2_convex_hull_.dir\main.cpp.i

CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\main.cpp" -o CMakeFiles\Lab_2_convex_hull_.dir\main.cpp.s

# Object files for target Lab_2_convex_hull_
Lab_2_convex_hull__OBJECTS = \
"CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.obj"

# External object files for target Lab_2_convex_hull_
Lab_2_convex_hull__EXTERNAL_OBJECTS =

Lab_2_convex_hull_.exe: CMakeFiles/Lab_2_convex_hull_.dir/main.cpp.obj
Lab_2_convex_hull_.exe: CMakeFiles/Lab_2_convex_hull_.dir/build.make
Lab_2_convex_hull_.exe: CMakeFiles/Lab_2_convex_hull_.dir/linklibs.rsp
Lab_2_convex_hull_.exe: CMakeFiles/Lab_2_convex_hull_.dir/objects1.rsp
Lab_2_convex_hull_.exe: CMakeFiles/Lab_2_convex_hull_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab_2_convex_hull_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_2_convex_hull_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_2_convex_hull_.dir/build: Lab_2_convex_hull_.exe

.PHONY : CMakeFiles/Lab_2_convex_hull_.dir/build

CMakeFiles/Lab_2_convex_hull_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_2_convex_hull_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_2_convex_hull_.dir/clean

CMakeFiles/Lab_2_convex_hull_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)" "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)" "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\cmake-build-debug" "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\cmake-build-debug" "D:\C++\1\1 course 1 term(2019)\Lab_2(convex hull)\cmake-build-debug\CMakeFiles\Lab_2_convex_hull_.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab_2_convex_hull_.dir/depend
