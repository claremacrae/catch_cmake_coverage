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

## Clare Macrae's extra notes

### Generating branch coverage

Based on [this question](https://stackoverflow.com/questions/12360167/generating-branch-coverage-data-for-lcov), you need to have the following lines enabled in your `~/.lcovrc` file:

```
genhtml_branch_coverage = 1
lcov_branch_coverage = 1
```

On a Mac, with lcov installed via brew, you will want to look at `/usr/local/etc/lcovrc`, not `/etc/lcovrc`

See the reference docs: [lcovrc - lcov configuration file](http://ltp.sourceforge.net/coverage/lcov/lcovrc.5.php).

### Excluding Catch2 test macros from the branch coverage

Add this to your `~/.lcovrc` file:

```
lcov_excl_br_line = LCOV_EXCL_BR_LINE|CHECK|REQUIRE
```
