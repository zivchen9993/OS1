# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/ziv/Programs/cmake-3.17.4-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/ziv/Programs/cmake-3.17.4-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/ziv/CLionProjects/smash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/smash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/smash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smash.dir/flags.make

CMakeFiles/smash.dir/commands.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/commands.cpp.o: ../commands.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/smash.dir/commands.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/commands.cpp.o -c /mnt/c/Users/ziv/CLionProjects/smash/commands.cpp

CMakeFiles/smash.dir/commands.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/commands.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ziv/CLionProjects/smash/commands.cpp > CMakeFiles/smash.dir/commands.cpp.i

CMakeFiles/smash.dir/commands.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/commands.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ziv/CLionProjects/smash/commands.cpp -o CMakeFiles/smash.dir/commands.cpp.s

CMakeFiles/smash.dir/signals.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/signals.cpp.o: ../signals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/smash.dir/signals.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/signals.cpp.o -c /mnt/c/Users/ziv/CLionProjects/smash/signals.cpp

CMakeFiles/smash.dir/signals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/signals.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ziv/CLionProjects/smash/signals.cpp > CMakeFiles/smash.dir/signals.cpp.i

CMakeFiles/smash.dir/signals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/signals.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ziv/CLionProjects/smash/signals.cpp -o CMakeFiles/smash.dir/signals.cpp.s

CMakeFiles/smash.dir/smash.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/smash.cpp.o: ../smash.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/smash.dir/smash.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/smash.cpp.o -c /mnt/c/Users/ziv/CLionProjects/smash/smash.cpp

CMakeFiles/smash.dir/smash.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/smash.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ziv/CLionProjects/smash/smash.cpp > CMakeFiles/smash.dir/smash.cpp.i

CMakeFiles/smash.dir/smash.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/smash.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ziv/CLionProjects/smash/smash.cpp -o CMakeFiles/smash.dir/smash.cpp.s

CMakeFiles/smash.dir/Terminal_class.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/Terminal_class.cpp.o: ../Terminal_class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/smash.dir/Terminal_class.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/Terminal_class.cpp.o -c /mnt/c/Users/ziv/CLionProjects/smash/Terminal_class.cpp

CMakeFiles/smash.dir/Terminal_class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/Terminal_class.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ziv/CLionProjects/smash/Terminal_class.cpp > CMakeFiles/smash.dir/Terminal_class.cpp.i

CMakeFiles/smash.dir/Terminal_class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/Terminal_class.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ziv/CLionProjects/smash/Terminal_class.cpp -o CMakeFiles/smash.dir/Terminal_class.cpp.s

CMakeFiles/smash.dir/Jobs.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/Jobs.cpp.o: ../Jobs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/smash.dir/Jobs.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/Jobs.cpp.o -c /mnt/c/Users/ziv/CLionProjects/smash/Jobs.cpp

CMakeFiles/smash.dir/Jobs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/Jobs.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ziv/CLionProjects/smash/Jobs.cpp > CMakeFiles/smash.dir/Jobs.cpp.i

CMakeFiles/smash.dir/Jobs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/Jobs.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ziv/CLionProjects/smash/Jobs.cpp -o CMakeFiles/smash.dir/Jobs.cpp.s

CMakeFiles/smash.dir/SingleJob.cpp.o: CMakeFiles/smash.dir/flags.make
CMakeFiles/smash.dir/SingleJob.cpp.o: ../SingleJob.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/smash.dir/SingleJob.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/smash.dir/SingleJob.cpp.o -c /mnt/c/Users/ziv/CLionProjects/smash/SingleJob.cpp

CMakeFiles/smash.dir/SingleJob.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smash.dir/SingleJob.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ziv/CLionProjects/smash/SingleJob.cpp > CMakeFiles/smash.dir/SingleJob.cpp.i

CMakeFiles/smash.dir/SingleJob.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smash.dir/SingleJob.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ziv/CLionProjects/smash/SingleJob.cpp -o CMakeFiles/smash.dir/SingleJob.cpp.s

# Object files for target smash
smash_OBJECTS = \
"CMakeFiles/smash.dir/commands.cpp.o" \
"CMakeFiles/smash.dir/signals.cpp.o" \
"CMakeFiles/smash.dir/smash.cpp.o" \
"CMakeFiles/smash.dir/Terminal_class.cpp.o" \
"CMakeFiles/smash.dir/Jobs.cpp.o" \
"CMakeFiles/smash.dir/SingleJob.cpp.o"

# External object files for target smash
smash_EXTERNAL_OBJECTS =

smash: CMakeFiles/smash.dir/commands.cpp.o
smash: CMakeFiles/smash.dir/signals.cpp.o
smash: CMakeFiles/smash.dir/smash.cpp.o
smash: CMakeFiles/smash.dir/Terminal_class.cpp.o
smash: CMakeFiles/smash.dir/Jobs.cpp.o
smash: CMakeFiles/smash.dir/SingleJob.cpp.o
smash: CMakeFiles/smash.dir/build.make
smash: CMakeFiles/smash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable smash"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smash.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smash.dir/build: smash

.PHONY : CMakeFiles/smash.dir/build

CMakeFiles/smash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/smash.dir/cmake_clean.cmake
.PHONY : CMakeFiles/smash.dir/clean

CMakeFiles/smash.dir/depend:
	cd /mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/ziv/CLionProjects/smash /mnt/c/Users/ziv/CLionProjects/smash /mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug /mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug /mnt/c/Users/ziv/CLionProjects/smash/cmake-build-debug/CMakeFiles/smash.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/smash.dir/depend

