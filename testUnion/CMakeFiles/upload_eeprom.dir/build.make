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
CMAKE_SOURCE_DIR = /home/dariusz/Arduino/nrf24l01-net/testUnion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dariusz/Arduino/nrf24l01-net/testUnion

# Utility rule file for upload_eeprom.

# Include the progress variables for this target.
include CMakeFiles/upload_eeprom.dir/progress.make

CMakeFiles/upload_eeprom: atmega8.eep
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Uploading atmega8.eep to atmega8 using arduino"
	avrdude -p atmega8 -c arduino -b57600 -U eeprom:w:/home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.eep -P /dev/ttyUSB0

atmega8.eep: bin/atmega8.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating atmega8.eep"
	/usr/bin/avr-objcopy -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex /home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.elf /home/dariusz/Arduino/nrf24l01-net/testUnion/bin/atmega8.eep

upload_eeprom: CMakeFiles/upload_eeprom
upload_eeprom: atmega8.eep
upload_eeprom: CMakeFiles/upload_eeprom.dir/build.make

.PHONY : upload_eeprom

# Rule to build all files generated by this target.
CMakeFiles/upload_eeprom.dir/build: upload_eeprom

.PHONY : CMakeFiles/upload_eeprom.dir/build

CMakeFiles/upload_eeprom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/upload_eeprom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/upload_eeprom.dir/clean

CMakeFiles/upload_eeprom.dir/depend:
	cd /home/dariusz/Arduino/nrf24l01-net/testUnion && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles/upload_eeprom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/upload_eeprom.dir/depend

