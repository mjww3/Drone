cmake_minimum_required(VERSION 2.8.3)
project(land)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  std_msgs
  pid
)

## System dependencies are found with CMake's conventions
## find_package(Boost REQUIRED COMPONENTS system)
 find_package(OpenCV REQUIRED)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   geometry_msgs#   std_msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES land
#  CATKIN_DEPENDS geometry_msgs opencv roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)

##Declare a C++ library
 ##add_library(
  ##src/battery/batterystatus.h
 ##)

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(land ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
 add_executable(landing_opencv_test 
 				src/opencvtest.cpp
 				src/battery/battery_status.h
        src/pid/pid.h
        src/pid/pid.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(landing_opencv_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(landing_opencv_test
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

## Declare a C++ executable
 add_executable(bgs_test 
 src/bgs/bgstest.cpp
 src/controller/controller.h
 src/controller/controller.cpp
 src/pid/pid.h
 src/pid/pid.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(bgs_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(bgs_test
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

 ##test orb
 ## Declare a C++ executable
  add_executable(orb_test src/orb_test/orb_test.cpp)

 ## Add cmake target dependencies of the executable
 ## same as for the library above
 add_dependencies(orb_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

 ## Specify libraries to link a library or executable target against
 target_link_libraries(orb_test
    ${catkin_LIBRARIES}
    ${OpenCV_LIBRARIES}
  )

  ##test rc_test
 ## Declare a C++ executable
  add_executable(rc_test 
  src/controller/controller.h
  src/controller/controller.cpp
  src/controller/control_utils.cpp)

 ## Add cmake target dependencies of the executable
 ## same as for the library above
 add_dependencies(rc_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

 ## Specify libraries to link a library or executable target against
 target_link_libraries(rc_test
    ${catkin_LIBRARIES}
    ${OpenCV_LIBRARIES}
  )

##test pid
 ## Declare a C++ executable
  add_executable(pid_test 
  src/pid/pid.h
  src/pid/pid.cpp
  src/pid/pid_test.cpp)

 ## Add cmake target dependencies of the executable
 ## same as for the library above
 add_dependencies(pid_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

 ## Specify libraries to link a library or executable target against
 target_link_libraries(pid_test
    ${catkin_LIBRARIES}
    ${OpenCV_LIBRARIES}
  )

##test publisher

## Declare a C++ executable
 add_executable(publisher_test src/testpublisher.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(publisher_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(publisher_test
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )


##test commands

## Declare a C++ executable
 add_executable(command_test src/circle_detect/detect_circle.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(command_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(command_test
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

##test background substraction

## Declare a C++ executable
 ##add_executable(bgs_subs_test 
 ##src/bgs_subs_test/test.cpp
 ##)

## Add cmake target dependencies of the executable
## same as for the library above
##add_dependencies(bgs_subs_test ${OpenCV_INCLUDE_DIRS} 
##${PROJECT_NAME}_EXPORTED_TARGETS}${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
##target_link_libraries(bgs_subs_test
  ## ${catkin_LIBRARIES}
   ##${OpenCV_LIBRARIES}
 ##)

##test_subscriber

## Declare a C++ executable
 add_executable(subscriber_test src/testsubscriber.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(subscriber_test ${OpenCV_INCLUDE_DIRS} ${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(subscriber_test
   ${catkin_LIBRARIES}
   ${OpenCV_LIBRARIES}
 )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS land land_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_land.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
