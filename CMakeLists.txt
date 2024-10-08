cmake_minimum_required(VERSION 3.14.0)

project(vega_project VERSION 1.0.0 LANGUAGES CXX)

if(CMAKE_HOST_SYSTEM MATCHES LINUX)
    set(CMAKE_CXX_FLAGS -pthread)
endif()
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(vega_main ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/fact.cpp)
target_link_directories(vega_main PUBLIC ${CMAKE_SOURCE_DIR}/src)

### TESTING 

enable_testing()

include(GoogleTest)
include(FetchContent)

# For Windows: Prevent overriding the parent project's compiler/linker settings
if(CMAKE_HOST_SYSTEM MATCHES WINDOWS)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
    )
FetchContent_MakeAvailable(googletest)

add_executable(vega_test ${CMAKE_SOURCE_DIR}/test/test.cpp ${CMAKE_SOURCE_DIR}/src/fact.cpp)
target_link_directories(vega_test PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(vega_test GTest::gtest_main)
gtest_discover_tests(vega_test)


### BENCHMARKING

set(BENCHMARK_ENABLE_TESTING NO)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG main
    )
FetchContent_MakeAvailable(googlebenchmark)

add_executable(vega_benchmark ${CMAKE_SOURCE_DIR}/benchmark/benchmark.cpp  ${CMAKE_SOURCE_DIR}/src/fact.cpp)
target_link_directories(vega_benchmark PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(vega_benchmark benchmark::benchmark_main)