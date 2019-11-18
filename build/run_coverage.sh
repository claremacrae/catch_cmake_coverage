cmake .. -DENABLE_CODE_COVERAGE=on
make unit_tests_coverage
open ./unit_tests_coverage/index.html
