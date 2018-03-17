cmake_minimum_required(VERSION 3.0)

project(cpp_design_patterns VERSION 0.0.1)

add_executable(ocp ${CMAKE_CURRENT_LIST_DIR}/OCP.cpp)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  "${CMAKE_CURRENT_BINARY_DIR}/journal.txt")
