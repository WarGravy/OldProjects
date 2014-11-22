cmake_minimum_required(VERSION 2.8.3)
project(listener)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS message_generation geometry_msgs std_msgs sensor_msgs tf)

catkin_package(
    CATKIN_DEPENDS message_runtime geometry_msgs sensor_msgs tf
    LIBRARIES lib
)

add_executable(listener src/listener.cc)
target_link_libraries(listener ${catkin_LIBRARIES})

install(TARGETS listener
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
