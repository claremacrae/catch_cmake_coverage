#ifndef CLASS_UNDER_TEST_H_
#define CLASS_UNDER_TEST_H_

#include <string>
#include <math.h>
using namespace std;

class ClassUnderTest
{
  public:
    int PublicMemberFunction(int multiplicand);
    string GetString(void);
    float GetPi(void);
};

#endif  // CLASS_UNDER_TEST_H_
