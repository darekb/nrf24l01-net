# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/dariusz/Arduino/nrf24l01-net/sensor11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dariusz/Arduino/nrf24l01-net/sensor11

# Utility rule file for upload_atmega8.

# Include the progress variables for this target.
include CMakeFiles/upload_atmega8.dir/progress.make

CMakeFiles/upload_atmega8: atmega8.hex
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/sensor11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Uploading atmega8.hex to atmega8 using usbasp"
	avrdude -p atmega8 -c usbasp -b38400 -U flash:w:/home/dariusz/Arduino/nrf24l01-net/sensor11/bin/atmega8.hex -P usb

atmega8.hex: bin/atmega8.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/sensor11/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating atmega8.hex"
	/usr/bin/avr-objcopy -j .text -j .data -O ihex /home/dariusz/Arduino/nrf24l01-net/sensor11/bin/atmega8.elf /home/dariusz/Arduino/nrf24l01-net/sensor11/bin/atmega8.hex
	/usr/bin/avr-size -C --mcu=atmega8 /home/dariusz/Arduino/nrf24l01-net/sensor11/bin/atmega8.elf

upload_atmega8: CMakeFiles/upload_atmega8
upload_atmega8: atmega8.hex
upload_atmega8: CMakeFiles/upload_atmega8.dir/build.make

.PHONY : upload_atmega8

# Rule to build all files generated by this target.
CMakeFiles/upload_atmega8.dir/build: upload_atmega8

.PHONY : CMakeFiles/upload_atmega8.dir/build

CMakeFiles/upload_atmega8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/upload_atmega8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/upload_atmega8.dir/clean

CMakeFiles/upload_atmega8.dir/depend:
	cd /home/dariusz/Arduino/nrf24l01-net/sensor11 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Arduino/nrf24l01-net/sensor11 /home/dariusz/Arduino/nrf24l01-net/sensor11 /home/dariusz/Arduino/nrf24l01-net/sensor11 /home/dariusz/Arduino/nrf24l01-net/sensor11 /home/dariusz/Arduino/nrf24l01-net/sensor11/CMakeFiles/upload_atmega8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/upload_atmega8.dir/depend

