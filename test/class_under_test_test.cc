#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "class_under_test.h"
#include <string>
#include <math.h>
using namespace std;

// does not break the test run because it fails
TEST_CASE("Check fails but does not break the test run", "[PublicMemberFunction]") {
  ClassUnderTest cut;
  int directTestInput = 1;
  int expectedDirectTestOutput = 42;
  CHECK(expectedDirectTestOutput == cut.PublicMemberFunction(directTestInput));
}

// would break the test run if it would fail
TEST_CASE("REQUIRE does break the test run", "[PublicMemberFunction]") {
  ClassUnderTest cut;
  int directTestInput = 1;
  int expectedDirectTestOutput = 42;
  REQUIRE(expectedDirectTestOutput == cut.PublicMemberFunction(directTestInput));
}

TEST_CASE("REQUIRE string", "[GetString]") {
  ClassUnderTest cut;
  string expectedDirectOutput = "Catch";
  REQUIRE(expectedDirectOutput == cut.GetString());
}

TEST_CASE("REQUIRE String to be FALSE", "[GetString]") {
  ClassUnderTest cut;
  string expectedDirectOutput = "Katch";
  REQUIRE_FALSE(expectedDirectOutput == cut.GetString());
}

TEST_CASE("REQUIRE APPROXimate float by error percentage") {
  ClassUnderTest cut;
  float allowedErrorPercentage = 0.10; // 10%
  float expectedDirectOutput = M_PI;  // pi
  REQUIRE(Approx(M_PI).epsilon(allowedErrorPercentage) == cut.GetPi());
}

TEST_CASE("REQUIRE APPROXimate float by absolute error") {
  ClassUnderTest cut;
  float allowedMargin = 0.41;
  float expectedDirectOutput = M_PI;  // pi
  REQUIRE(Approx(M_PI).margin(allowedMargin) == cut.GetPi());
}

TEST_CASE("Test condition coverage")
{
    int i = 40;
    if ( i > 40)
    {
        // When i is const, CLion's coverage shows this in grey, not red
        // The same is true of the lcov output
        std::cout << "true\n";
    }
    else
    {
        std::cout << "false\n";
    }
}

void process_bools(bool a, bool b, bool c, bool d)
{
    if (a && b && c && d )
    {
        cout << "cond 1 true\n";
    }
    if ((a || b) || (c || d))
    {
        cout << "cond 2 true\n";
    }
}

TEST_CASE("Test condition coverage of process_bools")
{
    auto both_bools = {true, false};
    for (auto a : both_bools)
    {
        for (auto b : both_bools)
        {
            for (auto c : both_bools)
            {
                for (auto d : both_bools)
                {
                    process_bools(a, b, c, d);
                }
            }
        }
    }
}
