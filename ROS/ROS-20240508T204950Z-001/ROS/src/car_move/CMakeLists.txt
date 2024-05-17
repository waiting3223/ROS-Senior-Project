cmake_minimum_required(VERSION 3.0.2)
project(car_move)

set(OpenCV_DIR /usr/share/OpenCV)
find_package(catkin REQUIRED COMPONENTS
  OpenCV
  OpenCV
  REQUIRED
  cv_bridge
  image_transport
  roscpp
  rospy
  sensor_msgs
  std_msgs
)

include_directories(
${catkin_INCLUDE_DIRS}
${OpenCV_LIBRARIES}
)


catkin_package(

)


add_executable(video src/video.cpp)

target_link_libraries(video
${catkin_LIBRARIES}
${OpenCV_LIBRARIES}
)




