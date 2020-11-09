cmake_minimum_required(VERSION 3.0.2)
project(robot_fun)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
  tf
)


catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})
add_executable(state_publisher src/state_publisher.cpp)
target_link_libraries(state_publisher ${catkin_LIBRARIES})



