# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/dariusz/bin/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/dariusz/bin/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dariusz/Arduino/nrf24l01-net/sensor21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dariusz/Arduino/nrf24l01-net/sensor21/cmake-build-debug

# Utility rule file for get_calibration.

# Include the progress variables for this target.
include CMakeFiles/get_calibration.dir/progress.make

CMakeFiles/get_calibration:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/sensor21/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Write calibration status of internal oscillator to atmega328p_calib.tmp."
	avrdude -p atmega328p -c usbasp -P usb -U calibration:r:/home/dariusz/Arduino/nrf24l01-net/sensor21/bin/atmega328p_calib.tmp:r

get_calibration: CMakeFiles/get_calibration
get_calibration: CMakeFiles/get_calibration.dir/build.make

.PHONY : get_calibration

# Rule to build all files generated by this target.
CMakeFiles/get_calibration.dir/build: get_calibration

.PHONY : CMakeFiles/get_calibration.dir/build

CMakeFiles/get_calibration.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/get_calibration.dir/cmake_clean.cmake
.PHONY : CMakeFiles/get_calibration.dir/clean

CMakeFiles/get_calibration.dir/depend:
	cd /home/dariusz/Arduino/nrf24l01-net/sensor21/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Arduino/nrf24l01-net/sensor21 /home/dariusz/Arduino/nrf24l01-net/sensor21 /home/dariusz/Arduino/nrf24l01-net/sensor21/cmake-build-debug /home/dariusz/Arduino/nrf24l01-net/sensor21/cmake-build-debug /home/dariusz/Arduino/nrf24l01-net/sensor21/cmake-build-debug/CMakeFiles/get_calibration.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/get_calibration.dir/depend

