# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build

# Include any dependencies generated for this target.
include test/CMakeFiles/test-direct-group.exe.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test-direct-group.exe.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test-direct-group.exe.dir/flags.make

test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o: test/CMakeFiles/test-direct-group.exe.dir/flags.make
test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o: /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/src/test/direct-group.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o"
	cd /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/test && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test-direct-group.exe.dir/direct-group.c.o   -c /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/src/test/direct-group.c

test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test-direct-group.exe.dir/direct-group.c.i"
	cd /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/test && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/src/test/direct-group.c > CMakeFiles/test-direct-group.exe.dir/direct-group.c.i

test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test-direct-group.exe.dir/direct-group.c.s"
	cd /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/test && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/src/test/direct-group.c -o CMakeFiles/test-direct-group.exe.dir/direct-group.c.s

test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.requires:

.PHONY : test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.requires

test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.provides: test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.requires
	$(MAKE) -f test/CMakeFiles/test-direct-group.exe.dir/build.make test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.provides.build
.PHONY : test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.provides

test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.provides.build: test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o


# Object files for target test-direct-group.exe
test__direct__group_exe_OBJECTS = \
"CMakeFiles/test-direct-group.exe.dir/direct-group.c.o"

# External object files for target test-direct-group.exe
test__direct__group_exe_EXTERNAL_OBJECTS =

test/test-direct-group.exe: test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o
test/test-direct-group.exe: test/CMakeFiles/test-direct-group.exe.dir/build.make
test/test-direct-group.exe: libh5-memvol.so
test/test-direct-group.exe: /usr/local/HDF_Group/HDF5/1.9.233/lib/libhdf5.so
test/test-direct-group.exe: test/CMakeFiles/test-direct-group.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test-direct-group.exe"
	cd /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test-direct-group.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test-direct-group.exe.dir/build: test/test-direct-group.exe

.PHONY : test/CMakeFiles/test-direct-group.exe.dir/build

test/CMakeFiles/test-direct-group.exe.dir/requires: test/CMakeFiles/test-direct-group.exe.dir/direct-group.c.o.requires

.PHONY : test/CMakeFiles/test-direct-group.exe.dir/requires

test/CMakeFiles/test-direct-group.exe.dir/clean:
	cd /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/test && $(CMAKE_COMMAND) -P CMakeFiles/test-direct-group.exe.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test-direct-group.exe.dir/clean

test/CMakeFiles/test-direct-group.exe.dir/depend:
	cd /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/src /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/src/test /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/test /home/paul/Documents/ProjektHDF5vol/ESD-Middleware/build/test/CMakeFiles/test-direct-group.exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test-direct-group.exe.dir/depend
