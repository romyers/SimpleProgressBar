# Included only for building tests and examples

cmake_minimum_required(VERSION 3.22.1...3.22.1)
project(SimpleProgressBar 
    VERSION 1.0 
    LANGUAGES CXX
)

add_executable(SimpleExample examples/SimpleExample.cpp)
target_include_directories(SimpleExample PRIVATE ${CMAKE_SOURCE_DIR}/include)

include(FetchContent)
include(CTest)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(testProgressBar tests/SimpleProgressBar.test.cpp)
target_link_libraries(testProgressBar PRIVATE gtest_main)
target_include_directories(testProgressBar PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME testProgressBar COMMAND testProgressBar)