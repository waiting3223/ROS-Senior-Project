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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/waiting/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/waiting/ROS/build

# Include any dependencies generated for this target.
include car_move/CMakeFiles/video.dir/depend.make

# Include the progress variables for this target.
include car_move/CMakeFiles/video.dir/progress.make

# Include the compile flags for this target's objects.
include car_move/CMakeFiles/video.dir/flags.make

car_move/CMakeFiles/video.dir/src/video.cpp.o: car_move/CMakeFiles/video.dir/flags.make
car_move/CMakeFiles/video.dir/src/video.cpp.o: /home/waiting/ROS/src/car_move/src/video.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/waiting/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object car_move/CMakeFiles/video.dir/src/video.cpp.o"
	cd /home/waiting/ROS/build/car_move && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/video.dir/src/video.cpp.o -c /home/waiting/ROS/src/car_move/src/video.cpp

car_move/CMakeFiles/video.dir/src/video.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/video.dir/src/video.cpp.i"
	cd /home/waiting/ROS/build/car_move && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/waiting/ROS/src/car_move/src/video.cpp > CMakeFiles/video.dir/src/video.cpp.i

car_move/CMakeFiles/video.dir/src/video.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/video.dir/src/video.cpp.s"
	cd /home/waiting/ROS/build/car_move && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/waiting/ROS/src/car_move/src/video.cpp -o CMakeFiles/video.dir/src/video.cpp.s

car_move/CMakeFiles/video.dir/src/video.cpp.o.requires:

.PHONY : car_move/CMakeFiles/video.dir/src/video.cpp.o.requires

car_move/CMakeFiles/video.dir/src/video.cpp.o.provides: car_move/CMakeFiles/video.dir/src/video.cpp.o.requires
	$(MAKE) -f car_move/CMakeFiles/video.dir/build.make car_move/CMakeFiles/video.dir/src/video.cpp.o.provides.build
.PHONY : car_move/CMakeFiles/video.dir/src/video.cpp.o.provides

car_move/CMakeFiles/video.dir/src/video.cpp.o.provides.build: car_move/CMakeFiles/video.dir/src/video.cpp.o


# Object files for target video
video_OBJECTS = \
"CMakeFiles/video.dir/src/video.cpp.o"

# External object files for target video
video_EXTERNAL_OBJECTS =

/home/waiting/ROS/devel/lib/car_move/video: car_move/CMakeFiles/video.dir/src/video.cpp.o
/home/waiting/ROS/devel/lib/car_move/video: car_move/CMakeFiles/video.dir/build.make
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libcv_bridge.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libimage_transport.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libmessage_filters.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libclass_loader.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/libPocoFoundation.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libdl.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libroslib.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/librospack.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libroscpp.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/librosconsole.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/librostime.so
/home/waiting/ROS/devel/lib/car_move/video: /opt/ros/melodic/lib/libcpp_common.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/waiting/ROS/devel/lib/car_move/video: car_move/CMakeFiles/video.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/waiting/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/waiting/ROS/devel/lib/car_move/video"
	cd /home/waiting/ROS/build/car_move && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/video.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
car_move/CMakeFiles/video.dir/build: /home/waiting/ROS/devel/lib/car_move/video

.PHONY : car_move/CMakeFiles/video.dir/build

car_move/CMakeFiles/video.dir/requires: car_move/CMakeFiles/video.dir/src/video.cpp.o.requires

.PHONY : car_move/CMakeFiles/video.dir/requires

car_move/CMakeFiles/video.dir/clean:
	cd /home/waiting/ROS/build/car_move && $(CMAKE_COMMAND) -P CMakeFiles/video.dir/cmake_clean.cmake
.PHONY : car_move/CMakeFiles/video.dir/clean

car_move/CMakeFiles/video.dir/depend:
	cd /home/waiting/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/waiting/ROS/src /home/waiting/ROS/src/car_move /home/waiting/ROS/build /home/waiting/ROS/build/car_move /home/waiting/ROS/build/car_move/CMakeFiles/video.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : car_move/CMakeFiles/video.dir/depend

