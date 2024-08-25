cmake_minimum_required(VERSION 3.10)
project(videocheck)

set(CMAKE_CXX_STANDARD 11)

# 指定生成文件的目錄
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 設置中間文件的目錄
set(CMAKE_CMAKEFILES_DIR ${CMAKE_BINARY_DIR}/CMakeFiles)
set(CMAKE_CACHEFILE_DIR ${CMAKE_BINARY_DIR}/CMakeCache.txt)

# 設置 CMake 生成的文件夾
set(CMAKE_CTEST_DIRECTORY ${CMAKE_BINARY_DIR}/CTest)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

# 設置測試結果的目錄
set(CMAKE_TEST_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test_results)

# 設置 catkin 生成的文件夾
set(CATKIN_DEVEL_PREFIX ${CMAKE_BINARY_DIR}/devel)
set(CATKIN_BUILD_PREFIX ${CMAKE_BINARY_DIR}/catkin_generated)

find_package(OpenCV REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

include_directories(${OpenCV_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})

add_executable(videocheck videocheck.cpp)
set_target_properties(videocheck PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
target_link_libraries(videocheck ${OpenCV_LIBS} ${catkin_LIBRARIES})