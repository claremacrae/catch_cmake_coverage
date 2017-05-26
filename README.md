# cmake_catch_coverage

Integration of CMake, Catch and CMake CodeCoverage module for C++ code.

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

    ch build/
    cmake ..
    make unit_tests_coverage
    xdg-open coverage/src/index.html
