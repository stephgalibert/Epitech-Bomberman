cmake_minimum_required(VERSION 2.8)

#project name is needed for dependency
project(gtest)

include_directories(
  ./
  ./include
)

add_library(gtest STATIC ./src/gtest-all.cc)

# set the build path of gtestlib
set_target_properties(gtest PROPERTIES
ARCHIVE_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR})
