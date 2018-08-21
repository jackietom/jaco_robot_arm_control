# Install script for directory: /home/zy/Documents/SummerResearch/jaco/control_ws2/src/jaco-ros/kinova_moveit/kinova_arm_moveit_demo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/zy/Documents/SummerResearch/jaco/control_ws2/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/zy/Documents/SummerResearch/jaco/control_ws2/build/jaco-ros/kinova_moveit/kinova_arm_moveit_demo/catkin_generated/installspace/kinova_arm_moveit_demo.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinova_arm_moveit_demo/cmake" TYPE FILE FILES
    "/home/zy/Documents/SummerResearch/jaco/control_ws2/build/jaco-ros/kinova_moveit/kinova_arm_moveit_demo/catkin_generated/installspace/kinova_arm_moveit_demoConfig.cmake"
    "/home/zy/Documents/SummerResearch/jaco/control_ws2/build/jaco-ros/kinova_moveit/kinova_arm_moveit_demo/catkin_generated/installspace/kinova_arm_moveit_demoConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/kinova_arm_moveit_demo" TYPE FILE FILES "/home/zy/Documents/SummerResearch/jaco/control_ws2/src/jaco-ros/kinova_moveit/kinova_arm_moveit_demo/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo" TYPE EXECUTABLE FILES "/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib/kinova_arm_moveit_demo/motion_plan")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan"
         OLD_RPATH "/opt/ros/kinetic/lib:/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan2")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan2"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo" TYPE EXECUTABLE FILES "/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib/kinova_arm_moveit_demo/motion_plan2")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan2" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan2")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan2"
         OLD_RPATH "/opt/ros/kinetic/lib:/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/motion_plan2")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/work_scene" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/work_scene")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/work_scene"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo" TYPE EXECUTABLE FILES "/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib/kinova_arm_moveit_demo/work_scene")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/work_scene" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/work_scene")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/work_scene"
         OLD_RPATH "/opt/ros/kinetic/lib:/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/work_scene")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/pick_place" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/pick_place")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/pick_place"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo" TYPE EXECUTABLE FILES "/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib/kinova_arm_moveit_demo/pick_place")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/pick_place" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/pick_place")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/pick_place"
         OLD_RPATH "/opt/ros/kinetic/lib:/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/pick_place")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/test_accuracy" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/test_accuracy")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/test_accuracy"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo" TYPE EXECUTABLE FILES "/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib/kinova_arm_moveit_demo/test_accuracy")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/test_accuracy" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/test_accuracy")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/test_accuracy"
         OLD_RPATH "/opt/ros/kinetic/lib:/home/zy/Documents/SummerResearch/jaco/control_ws2/devel/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/kinova_arm_moveit_demo/test_accuracy")
    endif()
  endif()
endif()

