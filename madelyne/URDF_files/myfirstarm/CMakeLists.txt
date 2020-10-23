cmake_minimum_required(VERSION 3.0.2)
project(testbot_description)

find_package(catkin REQUIRED COMPONENTS
  urdf
  rospy
  std_msgs
  sensor_msgs 
)

catkin_package()

catkin_install_python(PROGRAMS src/movethebot.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(movethebot ${PROJECT_SOURCE_DIR}/src/movethebot.py)



