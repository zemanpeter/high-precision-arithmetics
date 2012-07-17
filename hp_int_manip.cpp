#include <string>
#include <vector>
using namespace std;

#include "hpa.h"

namespace hpa
{

hp_int::hp_int()
{
  base = 10;
  sign = zero;
  digits.push_back(0);
}

void hp_int::set_base(usint b)
{
  if (2 <= b && b <= 36)
    base = b;
}

}
