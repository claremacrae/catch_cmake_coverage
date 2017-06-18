# cmake_catch_coverage

Integration of CMake, Catch and CMake CodeCoverage module for C++ code.
(CMake CodeCoverage depends on: gcov, gcovr, genhtml, lcov.)

## Setup

install test build environment tools (Ubuntu)

    ./setup.sh

## Usage

test build and test execution (without coverage)

    cd build/
    cmake ..
    make unit_tests
    ./unit_tests

test build, test execution (with coverage) and coverage observation

    cd build/
    cmake ..
    make unit_tests_coverage
    xdg-open ./coverage/index.html