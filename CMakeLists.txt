# Included only for building tests and examples

# TODO: Reduce min required CMake version
cmake_minimum_required(VERSION 3.22.1)
project(SimpleProgressBar 
    VERSION 1.0 
    DESCRIPTION "A simple console-based progress bar for C++"
    LANGUAGES CXX
)

OPTION(BUILD_TESTING "Build the Test Suite" OFF)
OPTION(BUILD_EXAMPLES "Build the Example Program" OFF)

# We only want to do this if we are the top-level project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) 

    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)

    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building documentation")
    endif()

endif()

add_library(SimpleProgressBar INTERFACE include/SimpleProgressBar.hpp)
target_include_directories(SimpleProgressBar INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(BUILD_EXAMPLES)

    add_executable(SimpleExample examples/SimpleExample.cpp)
    target_include_directories(SimpleExample PRIVATE ${CMAKE_SOURCE_DIR}/include)

endif()

if(BUILD_TESTING)

    include(FetchContent)
    include(CTest)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.6.0
    )
    FetchContent_MakeAvailable(Catch2)

    add_executable(testProgressBar tests/SimpleProgressBar.test.cpp)
    target_link_libraries(testProgressBar PRIVATE Catch2::Catch2WithMain SimpleProgressBar)
    add_test(NAME testProgressBar COMMAND testProgressBar)

    list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    include(Catch)
    catch_discover_tests(testProgressBar)

endif()