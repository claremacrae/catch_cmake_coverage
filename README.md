# cmake_catch_coverage

Integration of CMake, Catch and CMake CodeCoverage module for C++ code.
(CMake CodeCoverage depends on: gcov, gcovr, genhtml, lcov.)

## Setup

install test build environment tools (Ubuntu)

    ./setup.sh

## Usage

test build and test execution (with junit format .xml result piping into `build/unit_test_result.html`, without coverage analysis)

    cd build/
    cmake ..
    make unit_tests
    ./unit_tests -r junit > unit_test_result.xml

test build, test execution (with coverage analysis) and coverage observation

    cd build/
    cmake ..
    make unit_tests_coverage
    xdg-open ./coverage/index.html
