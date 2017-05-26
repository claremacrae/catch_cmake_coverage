cmake_minimum_required(VERSION 2.6)

set(catch_includes ${PROJECT_SOURCE_DIR}/ext)
set(includes_production ${PROJECT_SOURCE_DIR}/inc)
include_directories(${catch_includes} ${includes_production})

file(GLOB_RECURSE sources_production src/*.cc)
file(GLOB_RECURSE sources_test test/*.cc)

add_executable(unit_tests ${sources_test} ${sources_production})
target_link_libraries(unit_tests)
