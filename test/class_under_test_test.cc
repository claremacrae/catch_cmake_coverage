#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "class_under_test.h"

TEST_CASE("Valid multiplication result", "[PublicMemberFunction]") {
  ClassUnderTest cut;
  int directTestInput = 1;
  int expectedDirectTestOutput = 42;
  REQUIRE(expectedDirectTestOutput == cut.PublicMemberFunction(directTestInput));
}
