cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(vega_project VERSION 0.1.0 LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(vega_project src/main.cpp)