# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucasbatata/projetos/atm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucasbatata/projetos/atm/build

# Include any dependencies generated for this target.
include CMakeFiles/atm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/atm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/atm.dir/flags.make

CMakeFiles/atm.dir/src/dispenser.cpp.o: CMakeFiles/atm.dir/flags.make
CMakeFiles/atm.dir/src/dispenser.cpp.o: ../src/dispenser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucasbatata/projetos/atm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/atm.dir/src/dispenser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/atm.dir/src/dispenser.cpp.o -c /home/lucasbatata/projetos/atm/src/dispenser.cpp

CMakeFiles/atm.dir/src/dispenser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/atm.dir/src/dispenser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucasbatata/projetos/atm/src/dispenser.cpp > CMakeFiles/atm.dir/src/dispenser.cpp.i

CMakeFiles/atm.dir/src/dispenser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/atm.dir/src/dispenser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucasbatata/projetos/atm/src/dispenser.cpp -o CMakeFiles/atm.dir/src/dispenser.cpp.s

CMakeFiles/atm.dir/src/display.cpp.o: CMakeFiles/atm.dir/flags.make
CMakeFiles/atm.dir/src/display.cpp.o: ../src/display.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucasbatata/projetos/atm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/atm.dir/src/display.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/atm.dir/src/display.cpp.o -c /home/lucasbatata/projetos/atm/src/display.cpp

CMakeFiles/atm.dir/src/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/atm.dir/src/display.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucasbatata/projetos/atm/src/display.cpp > CMakeFiles/atm.dir/src/display.cpp.i

CMakeFiles/atm.dir/src/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/atm.dir/src/display.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucasbatata/projetos/atm/src/display.cpp -o CMakeFiles/atm.dir/src/display.cpp.s

CMakeFiles/atm.dir/src/keyboard.cpp.o: CMakeFiles/atm.dir/flags.make
CMakeFiles/atm.dir/src/keyboard.cpp.o: ../src/keyboard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucasbatata/projetos/atm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/atm.dir/src/keyboard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/atm.dir/src/keyboard.cpp.o -c /home/lucasbatata/projetos/atm/src/keyboard.cpp

CMakeFiles/atm.dir/src/keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/atm.dir/src/keyboard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucasbatata/projetos/atm/src/keyboard.cpp > CMakeFiles/atm.dir/src/keyboard.cpp.i

CMakeFiles/atm.dir/src/keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/atm.dir/src/keyboard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucasbatata/projetos/atm/src/keyboard.cpp -o CMakeFiles/atm.dir/src/keyboard.cpp.s

CMakeFiles/atm.dir/src/main.cpp.o: CMakeFiles/atm.dir/flags.make
CMakeFiles/atm.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucasbatata/projetos/atm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/atm.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/atm.dir/src/main.cpp.o -c /home/lucasbatata/projetos/atm/src/main.cpp

CMakeFiles/atm.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/atm.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucasbatata/projetos/atm/src/main.cpp > CMakeFiles/atm.dir/src/main.cpp.i

CMakeFiles/atm.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/atm.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucasbatata/projetos/atm/src/main.cpp -o CMakeFiles/atm.dir/src/main.cpp.s

# Object files for target atm
atm_OBJECTS = \
"CMakeFiles/atm.dir/src/dispenser.cpp.o" \
"CMakeFiles/atm.dir/src/display.cpp.o" \
"CMakeFiles/atm.dir/src/keyboard.cpp.o" \
"CMakeFiles/atm.dir/src/main.cpp.o"

# External object files for target atm
atm_EXTERNAL_OBJECTS =

atm: CMakeFiles/atm.dir/src/dispenser.cpp.o
atm: CMakeFiles/atm.dir/src/display.cpp.o
atm: CMakeFiles/atm.dir/src/keyboard.cpp.o
atm: CMakeFiles/atm.dir/src/main.cpp.o
atm: CMakeFiles/atm.dir/build.make
atm: CMakeFiles/atm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucasbatata/projetos/atm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable atm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/atm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/atm.dir/build: atm

.PHONY : CMakeFiles/atm.dir/build

CMakeFiles/atm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/atm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/atm.dir/clean

CMakeFiles/atm.dir/depend:
	cd /home/lucasbatata/projetos/atm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucasbatata/projetos/atm /home/lucasbatata/projetos/atm /home/lucasbatata/projetos/atm/build /home/lucasbatata/projetos/atm/build /home/lucasbatata/projetos/atm/build/CMakeFiles/atm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/atm.dir/depend

