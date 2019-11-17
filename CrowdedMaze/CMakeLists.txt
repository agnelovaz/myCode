cmake_minimum_required(VERSION 2.4)

project(CrowdedMaze)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(CrowdedMaze.cpp example_solution.cpp globals.cpp)
