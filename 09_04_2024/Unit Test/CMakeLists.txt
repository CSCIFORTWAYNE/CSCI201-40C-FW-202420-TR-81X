cmake_minimum_required(VERSION 3.22)
project(Test)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(student SHARED ../drink.cpp)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--wrap=main")

add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} student pthread)