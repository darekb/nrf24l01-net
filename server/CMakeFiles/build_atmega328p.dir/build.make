# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_SOURCE_DIR = /home/dariusz/Arduino/nrf24l01-net/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dariusz/Arduino/nrf24l01-net/server

# Utility rule file for build_atmega328p.

# Include the progress variables for this target.
include CMakeFiles/build_atmega328p.dir/progress.make

CMakeFiles/build_atmega328p: atmega328p.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Build atmega328p.hex for atmega328p"

atmega328p.hex: bin/atmega328p.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/server/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating atmega328p.hex"
	/usr/bin/avr-objcopy -j .text -j .data -O ihex /home/dariusz/Arduino/nrf24l01-net/server/bin/atmega328p.elf /home/dariusz/Arduino/nrf24l01-net/server/bin/atmega328p.hex
	/usr/bin/avr-size -C --mcu=atmega328p /home/dariusz/Arduino/nrf24l01-net/server/bin/atmega328p.elf

build_atmega328p: CMakeFiles/build_atmega328p
build_atmega328p: atmega328p.hex
build_atmega328p: CMakeFiles/build_atmega328p.dir/build.make

.PHONY : build_atmega328p

# Rule to build all files generated by this target.
CMakeFiles/build_atmega328p.dir/build: build_atmega328p

.PHONY : CMakeFiles/build_atmega328p.dir/build

CMakeFiles/build_atmega328p.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/build_atmega328p.dir/cmake_clean.cmake
.PHONY : CMakeFiles/build_atmega328p.dir/clean

CMakeFiles/build_atmega328p.dir/depend:
	cd /home/dariusz/Arduino/nrf24l01-net/server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Arduino/nrf24l01-net/server /home/dariusz/Arduino/nrf24l01-net/server /home/dariusz/Arduino/nrf24l01-net/server /home/dariusz/Arduino/nrf24l01-net/server /home/dariusz/Arduino/nrf24l01-net/server/CMakeFiles/build_atmega328p.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/build_atmega328p.dir/depend

