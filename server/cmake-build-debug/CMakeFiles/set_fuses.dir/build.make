# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/dariusz/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dariusz/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.5429.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dariusz/Elektronika/Arduino/nrf24l01-net/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug

# Utility rule file for set_fuses.

# Include the progress variables for this target.
include CMakeFiles/set_fuses.dir/progress.make

CMakeFiles/set_fuses:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Setup: High Fuse: 0xD8 Low Fuse: 0xFF"
	avrdude -p atmega328p -c usbasp -P usb -U lfuse:w:0xFF:m -U hfuse:w:0xD8:m

set_fuses: CMakeFiles/set_fuses
set_fuses: CMakeFiles/set_fuses.dir/build.make

.PHONY : set_fuses

# Rule to build all files generated by this target.
CMakeFiles/set_fuses.dir/build: set_fuses

.PHONY : CMakeFiles/set_fuses.dir/build

CMakeFiles/set_fuses.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/set_fuses.dir/cmake_clean.cmake
.PHONY : CMakeFiles/set_fuses.dir/clean

CMakeFiles/set_fuses.dir/depend:
	cd /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Elektronika/Arduino/nrf24l01-net/server /home/dariusz/Elektronika/Arduino/nrf24l01-net/server /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles/set_fuses.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set_fuses.dir/depend

