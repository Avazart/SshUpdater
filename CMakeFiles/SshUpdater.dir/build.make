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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivehor/SshUpdater

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivehor/SshUpdater

# Include any dependencies generated for this target.
include CMakeFiles/SshUpdater.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SshUpdater.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SshUpdater.dir/flags.make

CMakeFiles/SshUpdater.dir/Dir.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Dir.cpp.o: Dir.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SshUpdater.dir/Dir.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Dir.cpp.o -c /home/ivehor/SshUpdater/Dir.cpp

CMakeFiles/SshUpdater.dir/Dir.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Dir.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Dir.cpp > CMakeFiles/SshUpdater.dir/Dir.cpp.i

CMakeFiles/SshUpdater.dir/Dir.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Dir.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Dir.cpp -o CMakeFiles/SshUpdater.dir/Dir.cpp.s

CMakeFiles/SshUpdater.dir/Dir.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Dir.cpp.o.requires

CMakeFiles/SshUpdater.dir/Dir.cpp.o.provides: CMakeFiles/SshUpdater.dir/Dir.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Dir.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Dir.cpp.o.provides

CMakeFiles/SshUpdater.dir/Dir.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Dir.cpp.o


CMakeFiles/SshUpdater.dir/Process.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Process.cpp.o: Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SshUpdater.dir/Process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Process.cpp.o -c /home/ivehor/SshUpdater/Process.cpp

CMakeFiles/SshUpdater.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Process.cpp > CMakeFiles/SshUpdater.dir/Process.cpp.i

CMakeFiles/SshUpdater.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Process.cpp -o CMakeFiles/SshUpdater.dir/Process.cpp.s

CMakeFiles/SshUpdater.dir/Process.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Process.cpp.o.requires

CMakeFiles/SshUpdater.dir/Process.cpp.o.provides: CMakeFiles/SshUpdater.dir/Process.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Process.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Process.cpp.o.provides

CMakeFiles/SshUpdater.dir/Process.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Process.cpp.o


CMakeFiles/SshUpdater.dir/main.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SshUpdater.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/main.cpp.o -c /home/ivehor/SshUpdater/main.cpp

CMakeFiles/SshUpdater.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/main.cpp > CMakeFiles/SshUpdater.dir/main.cpp.i

CMakeFiles/SshUpdater.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/main.cpp -o CMakeFiles/SshUpdater.dir/main.cpp.s

CMakeFiles/SshUpdater.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/main.cpp.o.requires

CMakeFiles/SshUpdater.dir/main.cpp.o.provides: CMakeFiles/SshUpdater.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/main.cpp.o.provides

CMakeFiles/SshUpdater.dir/main.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/main.cpp.o


CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o: Ssh/Sftp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o -c /home/ivehor/SshUpdater/Ssh/Sftp.cpp

CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Ssh/Sftp.cpp > CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.i

CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Ssh/Sftp.cpp -o CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.s

CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.requires

CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.provides: CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.provides

CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o


CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o: Ssh/Ssh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o -c /home/ivehor/SshUpdater/Ssh/Ssh.cpp

CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Ssh/Ssh.cpp > CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.i

CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Ssh/Ssh.cpp -o CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.s

CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.requires

CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.provides: CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.provides

CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o


CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o: Ssh/SshChannel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o -c /home/ivehor/SshUpdater/Ssh/SshChannel.cpp

CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Ssh/SshChannel.cpp > CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.i

CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Ssh/SshChannel.cpp -o CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.s

CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.requires

CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.provides: CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.provides

CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o


CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o: Ssh/SshException.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o -c /home/ivehor/SshUpdater/Ssh/SshException.cpp

CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Ssh/SshException.cpp > CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.i

CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Ssh/SshException.cpp -o CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.s

CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.requires

CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.provides: CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.provides

CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o


CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o: Ssh/SshSession.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o -c /home/ivehor/SshUpdater/Ssh/SshSession.cpp

CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Ssh/SshSession.cpp > CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.i

CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Ssh/SshSession.cpp -o CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.s

CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.requires

CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.provides: CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.provides

CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o


CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o: CMakeFiles/SshUpdater.dir/flags.make
CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o: Ssh/SshUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o -c /home/ivehor/SshUpdater/Ssh/SshUtils.cpp

CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivehor/SshUpdater/Ssh/SshUtils.cpp > CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.i

CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivehor/SshUpdater/Ssh/SshUtils.cpp -o CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.s

CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.requires:

.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.requires

CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.provides: CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.requires
	$(MAKE) -f CMakeFiles/SshUpdater.dir/build.make CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.provides.build
.PHONY : CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.provides

CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.provides.build: CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o


# Object files for target SshUpdater
SshUpdater_OBJECTS = \
"CMakeFiles/SshUpdater.dir/Dir.cpp.o" \
"CMakeFiles/SshUpdater.dir/Process.cpp.o" \
"CMakeFiles/SshUpdater.dir/main.cpp.o" \
"CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o" \
"CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o" \
"CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o" \
"CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o" \
"CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o" \
"CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o"

# External object files for target SshUpdater
SshUpdater_EXTERNAL_OBJECTS =

SshUpdater: CMakeFiles/SshUpdater.dir/Dir.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/Process.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/main.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o
SshUpdater: CMakeFiles/SshUpdater.dir/build.make
SshUpdater: /usr/lib/i386-linux-gnu/libssh2.so
SshUpdater: CMakeFiles/SshUpdater.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivehor/SshUpdater/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable SshUpdater"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SshUpdater.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SshUpdater.dir/build: SshUpdater

.PHONY : CMakeFiles/SshUpdater.dir/build

CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Dir.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Process.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/main.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Ssh/Sftp.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Ssh/Ssh.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Ssh/SshChannel.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Ssh/SshException.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Ssh/SshSession.cpp.o.requires
CMakeFiles/SshUpdater.dir/requires: CMakeFiles/SshUpdater.dir/Ssh/SshUtils.cpp.o.requires

.PHONY : CMakeFiles/SshUpdater.dir/requires

CMakeFiles/SshUpdater.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SshUpdater.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SshUpdater.dir/clean

CMakeFiles/SshUpdater.dir/depend:
	cd /home/ivehor/SshUpdater && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivehor/SshUpdater /home/ivehor/SshUpdater /home/ivehor/SshUpdater /home/ivehor/SshUpdater /home/ivehor/SshUpdater/CMakeFiles/SshUpdater.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SshUpdater.dir/depend

