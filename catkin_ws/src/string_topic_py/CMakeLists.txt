# cmake_minimum_required(VERSION 3.0.2)
# project(string_topic_py)

# # 캐킨 빌드할 시 요구되는 구성 요소 패키지. 사용자가 만든 패키지가 의존하는 다른 패키지를 먼저 설치하는 옵션
# find_package(catkin REQUIRED COMPONENTS
#   roscpp
#   rospy
#   std_msgs
# )


# # ROS 이외의 패키지를 사용하는 예: Boost를 사용할 때 system 패키지를 설치하도록 함
# find_package(Boost REQUIRED COMPONENTS system)

# # 파이썬을 이용하기 위해 rospy를 사용할 때 설정하는 옵션. 파이썬 설치 프로세스인 setup.py를 부르는 역할
# #catkin_python_setup()

# # 메시지 파일을 추가
# # FILES: 현재 패키지 폴더의 msg 폴더 안의 .msg 파일들을 참조해 헤더 파일(.h)를 자동으로 생성한다는 의미
# # 만약 새 메시지를 만든다면 msg 폴더를 만든 뒤 그 안에 있는 메시지 파일 이름을 입력함. 여기에서는 MyMessage1.msg 등이 그 예.
# add_message_files(
#   FILES 
#   MyMessage1.msg
#   MyMessage2.msg
# )

# # 사용하는 서비스 파일을 추가. 방식은 메시지 파일과 같으며, 사용하려면 srv 폴더를 만든 뒤 해당 파일 이름을 입력해둬야 한다.
# add_service_files(
#   FILES
#   MyService.srv
# )

# # 사용하는 서비스 파일을 추가. 방식은 메시지, 서비스 파일과 같다.
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

# # 의존하는 메시지를 설정
# # DEPENDENCIES: 아래에 해당하는 메시지 패키지를 사용한다는 의미
# # std_msgs, sensor_msgs가 그 예시
# generate_messages(
#   std_msgs 
#   sensor_msgs
# )

# # 캐킨 빌드 옵션
# ## INCLUDE: 뒤에 설정한 패키지 내부 폴더인 include의 헤더 파일을 사용함
# ## LIBRARIES: 뒤에 설정한 패키지의 라이브러리를 사용함
# ## CATKIN_DEPENDS: 의존하는 패키지 지정
# ## DEPENDS: 시스템 의존 패키지
# catkin_package(
# #  INCLUDE_DIRS include
# #  LIBRARIES test_pkg
# #  CATKIN_DEPENDS roscpp rospy std_msgs
#   CATKIN_DEPENDS roscpp std_msgs message_runtime
# #  DEPENDS system_lib
# )

# # include 폴더 지정
# include_directories(
#   ${catkin_INCLUDE_DIRS} # 각 패키지 내의 include 폴더를 의미. 이 안의 헤더파일을 이용할 것. 
#   # 사용자가 추가할 때는 이 밑의 공간 이용
# )

# # 빌드 후 생성할 라이브러리. C++을 사용할 경우!
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/test_pkg.cpp
# )

# # 해당 라이브러리 및 실행파일을 빌드하기 전, 생성해야 할 의존성이 있는 메시지와 dynamic reconfigure이 있다면 우선으로 수행하도록 함
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

# # 빌드 후 생성할 실행파일에 대한 옵션 지정
# ## `__실행 파일 이름__` `__참조할 파일__` 순서대로 기재
# ## 복수 개의 참조 .cpp 파일이 있을 경우 한 괄호 뒤에 연속적으로 기재
# ## 생성할 실행파일이 2개 이상일 경우 add_executable 항목을 추가함
# add_executable(${PROJECT_NAME}_node src/test_pkg_node.cpp)

# # 지정 실행 파일을 생성하기 전, 링크해야 하는 라이브러리와 실행파일을 링크함
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

cmake_minimum_required(VERSION 3.0.2)
project(string_topic_py)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  message_generation # 추가
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


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
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
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

generate_messages(
  DEPENDENCIES
  std_msgs
) ###### 위 네 줄 추가

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
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
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS message_runtime ########## 추가!
#  INCLUDE_DIRS include
#  LIBRARIES topic_py2
#  CATKIN_DEPENDS rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/topic_py2.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/topic_py2_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
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
# catkin_add_gtest(${PROJECT_NAME}-test test/test_topic_py2.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
