cmake_minimum_required(VERSION 2.6)

project(catch_cmake_coverage)

set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Coverage specific configuration --- start
# required: Coverage or Debug
# (alternativelly via command line option: cmake -DCMAKE_BUILD_TYPE=Coverage ..)
set(CMAKE_BUILD_TYPE Coverage)

# add the project specific cmake modules directory to the cmake module path
# (w.r.t. CI/CD builds this is not the best approach)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# include the cmake code coverage module
include(CodeCoverage)

# test coverage build configuration for C++: debug build, no optimization, profiling enabled
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

# exclude /test and /ext directories from coverage analysis
set(LCOV_REMOVE_EXTRA "'test/*'" "'ext/*'")

# cmake code coverage module target
setup_target_for_coverage(unit_tests_coverage unit_tests coverage)
# --- Coverage specific configuration --- end

set(catch_includes ${PROJECT_SOURCE_DIR}/ext)
set(includes_production ${PROJECT_SOURCE_DIR}/inc)
include_directories(${catch_includes} ${includes_production})

file(GLOB_RECURSE sources_production src/*.cc)
file(GLOB_RECURSE sources_test test/*.cc)

add_executable(unit_tests ${sources_test} ${sources_production})
target_link_libraries(unit_tests)

# ---------------------------------------------
# Understanding the CMake mechanisms in this project
# TODO Understand/remove messages "clang: warning: argument unused during compilation: '--coverage' [-Wunused-command-line-argument]"
# TODO Understand how the targets work
# TODO Use the latest cmake coverage module - this will require changes to our cmake files first
# TODO Fix the errors "profiling: /Users/clare/Documents/develop/CMake/catch_cmake_coverage-claremacrae/cmake-build-debug/CMakeFiles/unit_tests.dir/test/class_under_test_test.cc.gcda: cannot merge previous GCDA file: corrupt arc tag (0x766e695f)"
# TODO Don't measure coverage in tests of Catch2 REQUIRE and CHECK macros

# ---------------------------------------------
# Understanding the code coverage capabilities
# TODO Understand what tools exactly are being used here
# TODO Understand how to clean out results of previous test runs
# TODO See whether HTML charts show unreachable lines in red (when new test is made const)

# ---------------------------------------------
# Understanding the CLion code coverage capabilities
# TODO Remove the need to set CMAKE_CXX_FLAGS here
# TODO Get CLion to show unreachable lines in red (when new test is made const)
