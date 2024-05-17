cmake_minimum_required(VERSION 2.8.3)
project(color_check)

set(OpenCV_DIR /usr/share/OpenCV)

find_package(catkin REQUIRED COMPONENTS
  OpenCV
  REQUIRED
  cv_bridge
  image_transport
  roscpp
  rospy
  sensor_msgs
  std_msgs
  
)

catkin_package(
)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

add_executable(color_finder_0 src/color_finder_0.cpp)

target_link_libraries(color_finder_0
${catkin_LIBRARIES}
${OpenCV_LIBRARIES}
)

add_executable(serial_test src/serial_test.cpp)

target_link_libraries(serial_test
${catkin_LIBRARIES}
)

add_executable(serial_1.0 src/serial_1.0.cpp)

target_link_libraries(serial_1.0
${catkin_LIBRARIES}
)

add_executable(serial_2.0 src/serial_2.0.cpp)

target_link_libraries(serial_2.0
${catkin_LIBRARIES}
)

add_executable(serial_3.0 src/serial_3.0.cpp)

target_link_libraries(serial_3.0
${catkin_LIBRARIES}
)







