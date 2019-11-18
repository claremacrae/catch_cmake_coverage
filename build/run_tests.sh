cmake .. -DENABLE_CODE_COVERAGE=on -DCMAKE_BUILD_TYPE=Debug
make unit_tests
./unit_tests -r junit > unit_test_result.xml
