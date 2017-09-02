#include "class_under_test.h"

int ClassUnderTest::PublicMemberFunction(int multiplicand){
  int multiplier = 42;
  return multiplier*multiplicand;
}

string ClassUnderTest::GetString(void){
  string something = "Catch";
  return something;
}

float ClassUnderTest::GetPi(void){
  return M_PI;
}
