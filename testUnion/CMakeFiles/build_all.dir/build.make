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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dariusz/Arduino/nrf24l01-net/testUnion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dariusz/Arduino/nrf24l01-net/testUnion

# Utility rule file for build_all.

# Include the progress variables for this target.
include CMakeFiles/build_all.dir/progress.make

CMakeFiles/build_all: atmega8.hex
CMakeFiles/build_all: atmega8.eep


atmega8.hex: bin/atmega8.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating atmega8.hex"
	/usr/bin/avr-objcopy -j .text -j .data -O ihex /home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.elf /home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.hex
	/usr/bin/avr-size -C --mcu=atmega8 /home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.elf

atmega8.eep: bin/atmega8.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating atmega8.eep"
	/usr/bin/avr-objcopy -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex /home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.elf /home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.eep

build_all: CMakeFiles/build_all
build_all: atmega8.hex
build_all: atmega8.eep
build_all: CMakeFiles/build_all.dir/build.make

.PHONY : build_all

# Rule to build all files generated by this target.
CMakeFiles/build_all.dir/build: build_all

.PHONY : CMakeFiles/build_all.dir/build

CMakeFiles/build_all.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/build_all.dir/cmake_clean.cmake
.PHONY : CMakeFiles/build_all.dir/clean

CMakeFiles/build_all.dir/depend:
	cd /home/dariusz/Arduino/nrf24l01-net/testUnion && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles/build_all.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/build_all.dir/depend

