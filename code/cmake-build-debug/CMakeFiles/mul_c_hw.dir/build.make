# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/vladislav/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vladislav/Desktop/clion-2021.2.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vladislav/Desktop/mul-c-hw/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mul_c_hw.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/mul_c_hw.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mul_c_hw.dir/flags.make

CMakeFiles/mul_c_hw.dir/main.c.o: CMakeFiles/mul_c_hw.dir/flags.make
CMakeFiles/mul_c_hw.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/mul_c_hw.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mul_c_hw.dir/main.c.o -c /home/vladislav/Desktop/mul-c-hw/code/main.c

CMakeFiles/mul_c_hw.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mul_c_hw.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislav/Desktop/mul-c-hw/code/main.c > CMakeFiles/mul_c_hw.dir/main.c.i

CMakeFiles/mul_c_hw.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mul_c_hw.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislav/Desktop/mul-c-hw/code/main.c -o CMakeFiles/mul_c_hw.dir/main.c.s

CMakeFiles/mul_c_hw.dir/talker.c.o: CMakeFiles/mul_c_hw.dir/flags.make
CMakeFiles/mul_c_hw.dir/talker.c.o: ../talker.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/mul_c_hw.dir/talker.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mul_c_hw.dir/talker.c.o -c /home/vladislav/Desktop/mul-c-hw/code/talker.c

CMakeFiles/mul_c_hw.dir/talker.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mul_c_hw.dir/talker.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislav/Desktop/mul-c-hw/code/talker.c > CMakeFiles/mul_c_hw.dir/talker.c.i

CMakeFiles/mul_c_hw.dir/talker.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mul_c_hw.dir/talker.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislav/Desktop/mul-c-hw/code/talker.c -o CMakeFiles/mul_c_hw.dir/talker.c.s

CMakeFiles/mul_c_hw.dir/container.c.o: CMakeFiles/mul_c_hw.dir/flags.make
CMakeFiles/mul_c_hw.dir/container.c.o: ../container.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/mul_c_hw.dir/container.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mul_c_hw.dir/container.c.o -c /home/vladislav/Desktop/mul-c-hw/code/container.c

CMakeFiles/mul_c_hw.dir/container.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mul_c_hw.dir/container.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislav/Desktop/mul-c-hw/code/container.c > CMakeFiles/mul_c_hw.dir/container.c.i

CMakeFiles/mul_c_hw.dir/container.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mul_c_hw.dir/container.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislav/Desktop/mul-c-hw/code/container.c -o CMakeFiles/mul_c_hw.dir/container.c.s

CMakeFiles/mul_c_hw.dir/name_generation.c.o: CMakeFiles/mul_c_hw.dir/flags.make
CMakeFiles/mul_c_hw.dir/name_generation.c.o: ../name_generation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/mul_c_hw.dir/name_generation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mul_c_hw.dir/name_generation.c.o -c /home/vladislav/Desktop/mul-c-hw/code/name_generation.c

CMakeFiles/mul_c_hw.dir/name_generation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mul_c_hw.dir/name_generation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vladislav/Desktop/mul-c-hw/code/name_generation.c > CMakeFiles/mul_c_hw.dir/name_generation.c.i

CMakeFiles/mul_c_hw.dir/name_generation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mul_c_hw.dir/name_generation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vladislav/Desktop/mul-c-hw/code/name_generation.c -o CMakeFiles/mul_c_hw.dir/name_generation.c.s

# Object files for target mul_c_hw
mul_c_hw_OBJECTS = \
"CMakeFiles/mul_c_hw.dir/main.c.o" \
"CMakeFiles/mul_c_hw.dir/talker.c.o" \
"CMakeFiles/mul_c_hw.dir/container.c.o" \
"CMakeFiles/mul_c_hw.dir/name_generation.c.o"

# External object files for target mul_c_hw
mul_c_hw_EXTERNAL_OBJECTS =

mul_c_hw: CMakeFiles/mul_c_hw.dir/main.c.o
mul_c_hw: CMakeFiles/mul_c_hw.dir/talker.c.o
mul_c_hw: CMakeFiles/mul_c_hw.dir/container.c.o
mul_c_hw: CMakeFiles/mul_c_hw.dir/name_generation.c.o
mul_c_hw: CMakeFiles/mul_c_hw.dir/build.make
mul_c_hw: CMakeFiles/mul_c_hw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable mul_c_hw"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mul_c_hw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mul_c_hw.dir/build: mul_c_hw
.PHONY : CMakeFiles/mul_c_hw.dir/build

CMakeFiles/mul_c_hw.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mul_c_hw.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mul_c_hw.dir/clean

CMakeFiles/mul_c_hw.dir/depend:
	cd /home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vladislav/Desktop/mul-c-hw/code /home/vladislav/Desktop/mul-c-hw/code /home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug /home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug /home/vladislav/Desktop/mul-c-hw/code/cmake-build-debug/CMakeFiles/mul_c_hw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mul_c_hw.dir/depend
