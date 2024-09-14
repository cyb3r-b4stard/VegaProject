cmake_minimum_required(VERSION 3.14.0)

project(vega_project VERSION 1.0.0 LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(vega_main ${CMAKE_SOURCE_DIR}/src/main.cpp)

### TESTING ###

enable_testing()

include(GoogleTest)
include(FetchContent)

# For Windows: Prevent overriding the parent project's compiler/linker settings
if(CMAKE_HOST_SYSTEM MATCHES Windows)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
    googletest
    # Specify the commit you depend on and update it regularly.
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    )
FetchContent_MakeAvailable(googletest)

add_executable(vega_test ${CMAKE_SOURCE_DIR}/test/test.cpp)
target_link_libraries(vega_test GTest::gtest_main)
gtest_discover_tests(vega_test)