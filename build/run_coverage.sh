cmake .. -DENABLE_CODE_COVERAGE=on -DCMAKE_BUILD_TYPE=Debug
make unit_tests_coverage
open ./unit_tests_coverage/index.html
