# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/175/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/175/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/cmake-build-debug

# Utility rule file for doc_doxygen.

# Include any custom commands dependencies for this target.
include CMakeFiles/doc_doxygen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/doc_doxygen.dir/progress.make

CMakeFiles/doc_doxygen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating API documentation with Doxygen"
	cd /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/estudiante && /usr/bin/doxygen /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/cmake-build-debug/Doxyfile

doc_doxygen: CMakeFiles/doc_doxygen
doc_doxygen: CMakeFiles/doc_doxygen.dir/build.make
.PHONY : doc_doxygen

# Rule to build all files generated by this target.
CMakeFiles/doc_doxygen.dir/build: doc_doxygen
.PHONY : CMakeFiles/doc_doxygen.dir/build

CMakeFiles/doc_doxygen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/doc_doxygen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/doc_doxygen.dir/clean

CMakeFiles/doc_doxygen.dir/depend:
	cd /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/cmake-build-debug /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/cmake-build-debug /home/manbolq/Escritorio/DGIIM/2º/1ºcuatrimestre/ED/practicas/practica3-colas_y_pilas/cmake-build-debug/CMakeFiles/doc_doxygen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/doc_doxygen.dir/depend

