cmake_minimum_required(VERSION 2.6)

project(catch_cmake_coverage)

set(CMAKE_VERBOSE_MAKEFILE off)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_CODE_COVERAGE "Enable coverage reporting" OFF)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Fix linker errors such as this, with clang-8:
    #   Undefined symbols for architecture x86_64:
    #     "std::runtime_error::what() const", referenced from:
    #         vtable for testing::internal::GoogleTestFailureException in libgtestd.a(gtest-all.cc.o)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lstdc++")
endif()

if(ENABLE_CODE_COVERAGE)
    message(STATUS "Enable Code Coverage")

    # --- Coverage specific configuration --- start
    # add the project specific cmake modules directory to the cmake module path
    # (w.r.t. CI/CD builds this is not the best approach)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

    # include the cmake code coverage module
    include(CodeCoverage)

    # Update the default compiler flags to enable coverage
    append_coverage_compiler_flags()

    # exclude /test and /ext directories from coverage analysis
    set(COVERAGE_LCOV_EXCLUDES "'test/*'" "'ext/*'")

    # cmake code coverage module target
    setup_target_for_coverage_lcov(
            NAME unit_tests_coverage
            EXECUTABLE unit_tests
            DEPENDENCIES unit_tests)
    # --- Coverage specific configuration --- end
endif()

set(catch_includes ${PROJECT_SOURCE_DIR}/ext)
set(includes_production ${PROJECT_SOURCE_DIR}/inc)
include_directories(${catch_includes} ${includes_production})

file(GLOB_RECURSE sources_production src/*.cc)
file(GLOB_RECURSE sources_test test/*.cc)

add_executable(unit_tests ${sources_test} ${sources_production})
target_link_libraries(unit_tests)
enable_testing()
add_test(NAME unit_tests COMMAND unit_tests)

# ---------------------------------------------
# Understanding the CMake mechanisms in this project
# TODO Understand/remove messages "clang: warning: argument unused during compilation: '--coverage' [-Wunused-command-line-argument]"
# TODO Fix the errors "profiling: /Users/clare/Documents/develop/CMake/catch_cmake_coverage-claremacrae/cmake-build-debug/CMakeFiles/unit_tests.dir/test/class_under_test_test.cc.gcda: cannot merge previous GCDA file: corrupt arc tag (0x766e695f)"

# ---------------------------------------------
# Understanding the code coverage capabilities
# TODO Understand what tools exactly are being used here
# TODO See whether HTML charts show unreachable lines in red (when new test is made const)

# ---------------------------------------------
# Understanding the CLion code coverage capabilities
# TODO Get CLion to show unreachable lines in red (when new test is made const)
