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

# Include any dependencies generated for this target.
include CMakeFiles/atmega328p.elf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/atmega328p.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/atmega328p.elf.dir/flags.make

CMakeFiles/atmega328p.elf.dir/main.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/atmega328p.elf.dir/main.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/main.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/main.c

CMakeFiles/atmega328p.elf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/main.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/main.c > CMakeFiles/atmega328p.elf.dir/main.c.i

CMakeFiles/atmega328p.elf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/main.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/main.c -o CMakeFiles/atmega328p.elf.dir/main.c.s

CMakeFiles/atmega328p.elf.dir/slUart.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/slUart.c.o: ../slUart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/atmega328p.elf.dir/slUart.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/slUart.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slUart.c

CMakeFiles/atmega328p.elf.dir/slUart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/slUart.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slUart.c > CMakeFiles/atmega328p.elf.dir/slUart.c.i

CMakeFiles/atmega328p.elf.dir/slUart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/slUart.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slUart.c -o CMakeFiles/atmega328p.elf.dir/slUart.c.s

CMakeFiles/atmega328p.elf.dir/slSPI.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/slSPI.c.o: ../slSPI.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/atmega328p.elf.dir/slSPI.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/slSPI.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slSPI.c

CMakeFiles/atmega328p.elf.dir/slSPI.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/slSPI.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slSPI.c > CMakeFiles/atmega328p.elf.dir/slSPI.c.i

CMakeFiles/atmega328p.elf.dir/slSPI.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/slSPI.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slSPI.c -o CMakeFiles/atmega328p.elf.dir/slSPI.c.s

CMakeFiles/atmega328p.elf.dir/slI2C.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/slI2C.c.o: ../slI2C.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/atmega328p.elf.dir/slI2C.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/slI2C.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slI2C.c

CMakeFiles/atmega328p.elf.dir/slI2C.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/slI2C.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slI2C.c > CMakeFiles/atmega328p.elf.dir/slI2C.c.i

CMakeFiles/atmega328p.elf.dir/slI2C.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/slI2C.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slI2C.c -o CMakeFiles/atmega328p.elf.dir/slI2C.c.s

CMakeFiles/atmega328p.elf.dir/slNRF24.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/slNRF24.c.o: ../slNRF24.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/atmega328p.elf.dir/slNRF24.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/slNRF24.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slNRF24.c

CMakeFiles/atmega328p.elf.dir/slNRF24.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/slNRF24.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slNRF24.c > CMakeFiles/atmega328p.elf.dir/slNRF24.c.i

CMakeFiles/atmega328p.elf.dir/slNRF24.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/slNRF24.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slNRF24.c -o CMakeFiles/atmega328p.elf.dir/slNRF24.c.s

CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.o: ../slBME180Measure.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slBME180Measure.c

CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slBME180Measure.c > CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.i

CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slBME180Measure.c -o CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.s

CMakeFiles/atmega328p.elf.dir/main_functions.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/main_functions.c.o: ../main_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/atmega328p.elf.dir/main_functions.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/main_functions.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/main_functions.c

CMakeFiles/atmega328p.elf.dir/main_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/main_functions.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/main_functions.c > CMakeFiles/atmega328p.elf.dir/main_functions.c.i

CMakeFiles/atmega328p.elf.dir/main_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/main_functions.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/main_functions.c -o CMakeFiles/atmega328p.elf.dir/main_functions.c.s

CMakeFiles/atmega328p.elf.dir/slPCF8563.c.o: CMakeFiles/atmega328p.elf.dir/flags.make
CMakeFiles/atmega328p.elf.dir/slPCF8563.c.o: ../slPCF8563.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/atmega328p.elf.dir/slPCF8563.c.o"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/atmega328p.elf.dir/slPCF8563.c.o   -c /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slPCF8563.c

CMakeFiles/atmega328p.elf.dir/slPCF8563.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/atmega328p.elf.dir/slPCF8563.c.i"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slPCF8563.c > CMakeFiles/atmega328p.elf.dir/slPCF8563.c.i

CMakeFiles/atmega328p.elf.dir/slPCF8563.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/atmega328p.elf.dir/slPCF8563.c.s"
	/usr/bin/avr-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/slPCF8563.c -o CMakeFiles/atmega328p.elf.dir/slPCF8563.c.s

# Object files for target atmega328p.elf
atmega328p_elf_OBJECTS = \
"CMakeFiles/atmega328p.elf.dir/main.c.o" \
"CMakeFiles/atmega328p.elf.dir/slUart.c.o" \
"CMakeFiles/atmega328p.elf.dir/slSPI.c.o" \
"CMakeFiles/atmega328p.elf.dir/slI2C.c.o" \
"CMakeFiles/atmega328p.elf.dir/slNRF24.c.o" \
"CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.o" \
"CMakeFiles/atmega328p.elf.dir/main_functions.c.o" \
"CMakeFiles/atmega328p.elf.dir/slPCF8563.c.o"

# External object files for target atmega328p.elf
atmega328p_elf_EXTERNAL_OBJECTS =

../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/main.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/slUart.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/slSPI.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/slI2C.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/slNRF24.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/slBME180Measure.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/main_functions.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/slPCF8563.c.o
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/build.make
../bin/atmega328p.elf: CMakeFiles/atmega328p.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable ../bin/atmega328p.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/atmega328p.elf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/atmega328p.elf.dir/build: ../bin/atmega328p.elf

.PHONY : CMakeFiles/atmega328p.elf.dir/build

CMakeFiles/atmega328p.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/atmega328p.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/atmega328p.elf.dir/clean

CMakeFiles/atmega328p.elf.dir/depend:
	cd /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dariusz/Elektronika/Arduino/nrf24l01-net/server /home/dariusz/Elektronika/Arduino/nrf24l01-net/server /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug /home/dariusz/Elektronika/Arduino/nrf24l01-net/server/cmake-build-debug/CMakeFiles/atmega328p.elf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/atmega328p.elf.dir/depend

