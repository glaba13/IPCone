# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\first\IPCone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\first\IPCone\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/client.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/client.cpp.obj: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/client.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\client.cpp.obj -c E:\first\IPCone\client.cpp

CMakeFiles/Client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/client.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\client.cpp > CMakeFiles\Client.dir\client.cpp.i

CMakeFiles/Client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/client.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\client.cpp -o CMakeFiles\Client.dir\client.cpp.s

CMakeFiles/Client.dir/client.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/client.cpp.obj.requires

CMakeFiles/Client.dir/client.cpp.obj.provides: CMakeFiles/Client.dir/client.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/client.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/client.cpp.obj.provides

CMakeFiles/Client.dir/client.cpp.obj.provides.build: CMakeFiles/Client.dir/client.cpp.obj


CMakeFiles/Client.dir/Receiver.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Receiver.cpp.obj: ../Receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/Receiver.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\Receiver.cpp.obj -c E:\first\IPCone\Receiver.cpp

CMakeFiles/Client.dir/Receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Receiver.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\Receiver.cpp > CMakeFiles\Client.dir\Receiver.cpp.i

CMakeFiles/Client.dir/Receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Receiver.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\Receiver.cpp -o CMakeFiles\Client.dir\Receiver.cpp.s

CMakeFiles/Client.dir/Receiver.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/Receiver.cpp.obj.requires

CMakeFiles/Client.dir/Receiver.cpp.obj.provides: CMakeFiles/Client.dir/Receiver.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/Receiver.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/Receiver.cpp.obj.provides

CMakeFiles/Client.dir/Receiver.cpp.obj.provides.build: CMakeFiles/Client.dir/Receiver.cpp.obj


CMakeFiles/Client.dir/MessageBuilder.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/MessageBuilder.cpp.obj: ../MessageBuilder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/MessageBuilder.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\MessageBuilder.cpp.obj -c E:\first\IPCone\MessageBuilder.cpp

CMakeFiles/Client.dir/MessageBuilder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/MessageBuilder.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\MessageBuilder.cpp > CMakeFiles\Client.dir\MessageBuilder.cpp.i

CMakeFiles/Client.dir/MessageBuilder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/MessageBuilder.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\MessageBuilder.cpp -o CMakeFiles\Client.dir\MessageBuilder.cpp.s

CMakeFiles/Client.dir/MessageBuilder.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/MessageBuilder.cpp.obj.requires

CMakeFiles/Client.dir/MessageBuilder.cpp.obj.provides: CMakeFiles/Client.dir/MessageBuilder.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/MessageBuilder.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/MessageBuilder.cpp.obj.provides

CMakeFiles/Client.dir/MessageBuilder.cpp.obj.provides.build: CMakeFiles/Client.dir/MessageBuilder.cpp.obj


CMakeFiles/Client.dir/Serilizer.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Serilizer.cpp.obj: ../Serilizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/Serilizer.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\Serilizer.cpp.obj -c E:\first\IPCone\Serilizer.cpp

CMakeFiles/Client.dir/Serilizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Serilizer.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\Serilizer.cpp > CMakeFiles\Client.dir\Serilizer.cpp.i

CMakeFiles/Client.dir/Serilizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Serilizer.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\Serilizer.cpp -o CMakeFiles\Client.dir\Serilizer.cpp.s

CMakeFiles/Client.dir/Serilizer.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/Serilizer.cpp.obj.requires

CMakeFiles/Client.dir/Serilizer.cpp.obj.provides: CMakeFiles/Client.dir/Serilizer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/Serilizer.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/Serilizer.cpp.obj.provides

CMakeFiles/Client.dir/Serilizer.cpp.obj.provides.build: CMakeFiles/Client.dir/Serilizer.cpp.obj


CMakeFiles/Client.dir/Sender.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Sender.cpp.obj: ../Sender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/Sender.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\Sender.cpp.obj -c E:\first\IPCone\Sender.cpp

CMakeFiles/Client.dir/Sender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Sender.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\Sender.cpp > CMakeFiles\Client.dir\Sender.cpp.i

CMakeFiles/Client.dir/Sender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Sender.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\Sender.cpp -o CMakeFiles\Client.dir\Sender.cpp.s

CMakeFiles/Client.dir/Sender.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/Sender.cpp.obj.requires

CMakeFiles/Client.dir/Sender.cpp.obj.provides: CMakeFiles/Client.dir/Sender.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/Sender.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/Sender.cpp.obj.provides

CMakeFiles/Client.dir/Sender.cpp.obj.provides.build: CMakeFiles/Client.dir/Sender.cpp.obj


CMakeFiles/Client.dir/Deserilizer.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Deserilizer.cpp.obj: ../Deserilizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Client.dir/Deserilizer.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\Deserilizer.cpp.obj -c E:\first\IPCone\Deserilizer.cpp

CMakeFiles/Client.dir/Deserilizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Deserilizer.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\Deserilizer.cpp > CMakeFiles\Client.dir\Deserilizer.cpp.i

CMakeFiles/Client.dir/Deserilizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Deserilizer.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\Deserilizer.cpp -o CMakeFiles\Client.dir\Deserilizer.cpp.s

CMakeFiles/Client.dir/Deserilizer.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/Deserilizer.cpp.obj.requires

CMakeFiles/Client.dir/Deserilizer.cpp.obj.provides: CMakeFiles/Client.dir/Deserilizer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/Deserilizer.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/Deserilizer.cpp.obj.provides

CMakeFiles/Client.dir/Deserilizer.cpp.obj.provides.build: CMakeFiles/Client.dir/Deserilizer.cpp.obj


CMakeFiles/Client.dir/OperatorResolver.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/OperatorResolver.cpp.obj: ../OperatorResolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Client.dir/OperatorResolver.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\OperatorResolver.cpp.obj -c E:\first\IPCone\OperatorResolver.cpp

CMakeFiles/Client.dir/OperatorResolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/OperatorResolver.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\OperatorResolver.cpp > CMakeFiles\Client.dir\OperatorResolver.cpp.i

CMakeFiles/Client.dir/OperatorResolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/OperatorResolver.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\OperatorResolver.cpp -o CMakeFiles\Client.dir\OperatorResolver.cpp.s

CMakeFiles/Client.dir/OperatorResolver.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/OperatorResolver.cpp.obj.requires

CMakeFiles/Client.dir/OperatorResolver.cpp.obj.provides: CMakeFiles/Client.dir/OperatorResolver.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/OperatorResolver.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/OperatorResolver.cpp.obj.provides

CMakeFiles/Client.dir/OperatorResolver.cpp.obj.provides.build: CMakeFiles/Client.dir/OperatorResolver.cpp.obj


CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj: ../Examples/ExampleFunctions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\Examples\ExampleFunctions.cpp.obj -c E:\first\IPCone\Examples\ExampleFunctions.cpp

CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\Examples\ExampleFunctions.cpp > CMakeFiles\Client.dir\Examples\ExampleFunctions.cpp.i

CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\Examples\ExampleFunctions.cpp -o CMakeFiles\Client.dir\Examples\ExampleFunctions.cpp.s

CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.requires

CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.provides: CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.provides

CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.provides.build: CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj


CMakeFiles/Client.dir/Examples/Movie.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Examples/Movie.cpp.obj: ../Examples/Movie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Client.dir/Examples/Movie.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\Examples\Movie.cpp.obj -c E:\first\IPCone\Examples\Movie.cpp

CMakeFiles/Client.dir/Examples/Movie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Examples/Movie.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\Examples\Movie.cpp > CMakeFiles\Client.dir\Examples\Movie.cpp.i

CMakeFiles/Client.dir/Examples/Movie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Examples/Movie.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\Examples\Movie.cpp -o CMakeFiles\Client.dir\Examples\Movie.cpp.s

CMakeFiles/Client.dir/Examples/Movie.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/Examples/Movie.cpp.obj.requires

CMakeFiles/Client.dir/Examples/Movie.cpp.obj.provides: CMakeFiles/Client.dir/Examples/Movie.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/Examples/Movie.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/Examples/Movie.cpp.obj.provides

CMakeFiles/Client.dir/Examples/Movie.cpp.obj.provides.build: CMakeFiles/Client.dir/Examples/Movie.cpp.obj


CMakeFiles/Client.dir/Examples/Cinema.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/Examples/Cinema.cpp.obj: ../Examples/Cinema.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Client.dir/Examples/Cinema.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\Examples\Cinema.cpp.obj -c E:\first\IPCone\Examples\Cinema.cpp

CMakeFiles/Client.dir/Examples/Cinema.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/Examples/Cinema.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\Examples\Cinema.cpp > CMakeFiles\Client.dir\Examples\Cinema.cpp.i

CMakeFiles/Client.dir/Examples/Cinema.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/Examples/Cinema.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\Examples\Cinema.cpp -o CMakeFiles\Client.dir\Examples\Cinema.cpp.s

CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.requires

CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.provides: CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.provides

CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.provides.build: CMakeFiles/Client.dir/Examples/Cinema.cpp.obj


CMakeFiles/Client.dir/ObjectPool.cpp.obj: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/ObjectPool.cpp.obj: ../ObjectPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Client.dir/ObjectPool.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Client.dir\ObjectPool.cpp.obj -c E:\first\IPCone\ObjectPool.cpp

CMakeFiles/Client.dir/ObjectPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/ObjectPool.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\first\IPCone\ObjectPool.cpp > CMakeFiles\Client.dir\ObjectPool.cpp.i

CMakeFiles/Client.dir/ObjectPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/ObjectPool.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\first\IPCone\ObjectPool.cpp -o CMakeFiles\Client.dir\ObjectPool.cpp.s

CMakeFiles/Client.dir/ObjectPool.cpp.obj.requires:

.PHONY : CMakeFiles/Client.dir/ObjectPool.cpp.obj.requires

CMakeFiles/Client.dir/ObjectPool.cpp.obj.provides: CMakeFiles/Client.dir/ObjectPool.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Client.dir\build.make CMakeFiles/Client.dir/ObjectPool.cpp.obj.provides.build
.PHONY : CMakeFiles/Client.dir/ObjectPool.cpp.obj.provides

CMakeFiles/Client.dir/ObjectPool.cpp.obj.provides.build: CMakeFiles/Client.dir/ObjectPool.cpp.obj


# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/client.cpp.obj" \
"CMakeFiles/Client.dir/Receiver.cpp.obj" \
"CMakeFiles/Client.dir/MessageBuilder.cpp.obj" \
"CMakeFiles/Client.dir/Serilizer.cpp.obj" \
"CMakeFiles/Client.dir/Sender.cpp.obj" \
"CMakeFiles/Client.dir/Deserilizer.cpp.obj" \
"CMakeFiles/Client.dir/OperatorResolver.cpp.obj" \
"CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj" \
"CMakeFiles/Client.dir/Examples/Movie.cpp.obj" \
"CMakeFiles/Client.dir/Examples/Cinema.cpp.obj" \
"CMakeFiles/Client.dir/ObjectPool.cpp.obj"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client.exe: CMakeFiles/Client.dir/client.cpp.obj
Client.exe: CMakeFiles/Client.dir/Receiver.cpp.obj
Client.exe: CMakeFiles/Client.dir/MessageBuilder.cpp.obj
Client.exe: CMakeFiles/Client.dir/Serilizer.cpp.obj
Client.exe: CMakeFiles/Client.dir/Sender.cpp.obj
Client.exe: CMakeFiles/Client.dir/Deserilizer.cpp.obj
Client.exe: CMakeFiles/Client.dir/OperatorResolver.cpp.obj
Client.exe: CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj
Client.exe: CMakeFiles/Client.dir/Examples/Movie.cpp.obj
Client.exe: CMakeFiles/Client.dir/Examples/Cinema.cpp.obj
Client.exe: CMakeFiles/Client.dir/ObjectPool.cpp.obj
Client.exe: CMakeFiles/Client.dir/build.make
Client.exe: CMakeFiles/Client.dir/linklibs.rsp
Client.exe: CMakeFiles/Client.dir/objects1.rsp
Client.exe: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\first\IPCone\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable Client.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Client.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client.exe

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/client.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Receiver.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/MessageBuilder.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Serilizer.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Sender.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Deserilizer.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/OperatorResolver.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Examples/ExampleFunctions.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Examples/Movie.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/Examples/Cinema.cpp.obj.requires
CMakeFiles/Client.dir/requires: CMakeFiles/Client.dir/ObjectPool.cpp.obj.requires

.PHONY : CMakeFiles/Client.dir/requires

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Client.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\first\IPCone E:\first\IPCone E:\first\IPCone\cmake-build-debug E:\first\IPCone\cmake-build-debug E:\first\IPCone\cmake-build-debug\CMakeFiles\Client.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

