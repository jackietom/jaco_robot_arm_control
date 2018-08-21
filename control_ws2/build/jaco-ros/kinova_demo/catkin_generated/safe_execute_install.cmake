execute_process(COMMAND "/home/zy/Documents/SummerResearch/jaco/control_ws2/build/jaco-ros/kinova_demo/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/zy/Documents/SummerResearch/jaco/control_ws2/build/jaco-ros/kinova_demo/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
