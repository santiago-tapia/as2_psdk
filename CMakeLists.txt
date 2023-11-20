cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME as2_psdk)
project(${PROJECT_NAME})

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# set Release as default
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# find dependencies
set(PROJECT_DEPENDENCIES
  ament_cmake
  rclcpp
  as2_core
  as2_msgs
  std_srvs
  std_msgs
)

message(STATUS "Looking for dependencies")

foreach(DEPENDENCY ${PROJECT_DEPENDENCIES})
  find_package(${DEPENDENCY} REQUIRED)
  if(${DEPENDENCY}_FOUND)
    message(STATUS "${DEPENDENCY} was found")
  else()
    message(STATUS "${DEPENDENCY} was not found")
  endif()  
endforeach()

include_directories(
  include
  include/${PROJECT_NAME}
  #uncomment if using Eigen3
  #{EIGEN3_INCLUDE_DIRS} 
)

set(SOURCE_CPP_FILES 
  src/as2_node_template.cpp
)

add_executable(${PROJECT_NAME}_node src/main.cpp ${SOURCE_CPP_FILES})
ament_target_dependencies(${PROJECT_NAME}_node ${PROJECT_DEPENDENCIES})
target_precompile_headers(${PROJECT_NAME}_node
  PRIVATE
    [["rclcpp/rclcpp.hpp"]]
)

#set fPIC to ON by default (For Dynamic Link Libraries)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# The library name is the PROJECT_NAME
add_library(${PROJECT_NAME} SHARED ${SOURCE_CPP_FILES} )
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(${PROJECT_NAME} ${PROJECT_DEPENDENCIES})
# Do not reuse pch because -fPIC is ON for libraries
target_precompile_headers(${PROJECT_NAME}
  PRIVATE
    [["rclcpp/rclcpp.hpp"]]
)
ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(${PROJECT_DEPENDENCIES})

# These are superfluous for target based installs:
# (See https://docs.ros.org/en/rolling/How-To-Guides/Ament-CMake-Documentation.html)
ament_export_libraries(${PROJECT_NAME})
ament_export_include_directories("include/${PROJECT_NAME}")

# Install 

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

install(
  TARGETS ${PROJECT_NAME}_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_cmake_cppcheck REQUIRED)
  find_package(ament_cmake_clang_format REQUIRED)
  
  ament_cppcheck(src/ include/ tests/)
  ament_clang_format(src/ include/ tests/ --config ${CMAKE_CURRENT_SOURCE_DIR}/.clang-format)
endif()
    
ament_package()
