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

# Include any dependencies generated for this target.
include CMakeFiles/atmega328p.elf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/atmega328p.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/atmega328p.elf.dir/flags.make

CMakeFiles/atmega328p.elf.dir/main.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/atmega328p.elf.dir/main.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/main.c.o   -c /home/dariusz/Arduino/nrf24l01-net/testUnion/main.c

CMakeFiles/atmega328p.elf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/main.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Arduino/nrf24l01-net/testUnion/main.c > CMakeFiles/atmega328p.elf.dir/main.c.i

CMakeFiles/atmega328p.elf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/main.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Arduino/nrf24l01-net/testUnion/main.c -o CMakeFiles/atmega328p.elf.dir/main.c.s

CMakeFiles/atmega328p.elf.dir/main.c.o.requires:

.PHONY : CMakeFiles/atmega328p.elf.dir/main.c.o.requires

CMakeFiles/atmega328p.elf.dir/main.c.o.provides: CMakeFiles/atmega328p.elf.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/atmega328p.elf.dir/build.make CMakeFiles/atmega328p.elf.dir/main.c.o.provides.build
.PHONY : CMakeFiles/atmega328p.elf.dir/main.c.o.provides

CMakeFiles/atmega328p.elf.dir/main.c.o.provides.build: CMakeFiles/atmega328p.elf.dir/main.c.o


CMakeFiles/atmega328p.elf.dir/slUart.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/slUart.c.o: slUart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/atmega328p.elf.dir/slUart.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/slUart.c.o   -c /home/dariusz/Arduino/nrf24l01-net/testUnion/slUart.c

CMakeFiles/atmega328p.elf.dir/slUart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/slUart.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Arduino/nrf24l01-net/testUnion/slUart.c > CMakeFiles/atmega328p.elf.dir/slUart.c.i

CMakeFiles/atmega328p.elf.dir/slUart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/slUart.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Arduino/nrf24l01-net/testUnion/slUart.c -o CMakeFiles/atmega328p.elf.dir/slUart.c.s

CMakeFiles/atmega328p.elf.dir/slUart.c.o.requires:

.PHONY : CMakeFiles/atmega328p.elf.dir/slUart.c.o.requires

CMakeFiles/atmega328p.elf.dir/slUart.c.o.provides: CMakeFiles/atmega328p.elf.dir/slUart.c.o.requires
	$(MAKE) -f CMakeFiles/atmega328p.elf.dir/build.make CMakeFiles/atmega328p.elf.dir/slUart.c.o.provides.build
.PHONY : CMakeFiles/atmega328p.elf.dir/slUart.c.o.provides

CMakeFiles/atmega328p.elf.dir/slUart.c.o.provides.build: CMakeFiles/atmega328p.elf.dir/slUart.c.o


# Object files for target atmega328p.elf
atmega328p_elf_OBJECTS = \
"CMakeFiles/atmega328p.elf.dir/main.c.o" \
"CMakeFiles/atmega328p.elf.dir/slUart.c.o"

# External object files for target atmega328p.elf
atmega328p_elf_EXTERNAL_OBJECTS =

bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/main.c.o
bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/slUart.c.o
bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/build.make
bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bin/atmega328p.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/atmega328p.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/atmega328p.elf.dir/build: bin/atmega328p.elf

.PHONY : CMakeFiles/atmega328p.elf.dir/build

CMakeFiles/atmega328p.elf.dir/requires: CMakeFiles/atmega328p.elf.dir/main.c.o.requires
CMakeFiles/atmega328p.elf.dir/requires: CMakeFiles/atmega328p.elf.dir/slUart.c.o.requires

.PHONY : CMakeFiles/atmega328p.elf.dir/requires

CMakeFiles/atmega328p.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/atmega328p.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/atmega328p.elf.dir/clean

CMakeFiles/atmega328p.elf.dir/depend:
	cd /home/dariusz/Arduino/nrf24l01-net/testUnion && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion /home/dariusz/Arduino/nrf24l01-net/testUnion/CMakeFiles/atmega328p.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/atmega328p.elf.dir/depend

