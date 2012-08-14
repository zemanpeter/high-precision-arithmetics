#include "hp_uint.h"

using namespace std;

namespace hpa
{

void hp_uint::div_and_mod(hp_uint& q, hp_uint& r, const hp_uint& a, const hp_uint& b)
{
  if (a.digits.size() == 1 && a.digits[0] == 0)
    return;

  hp_uint q1, r1, adtwo = a;
  
  adtwo.divide_by_two();
  div_and_mod(q1, r1, adtwo, b);
  q1 = q1 * hp_uint("2");
  r1 = r1 * hp_uint("2");
  if (a.digits[0] % 2 == 1)
    r1 = r1 + hp_uint("1");
  if (r1 >= b) {
    r1 = r1 - b;
    q1 = q1 + hp_uint("1");
  }

  q = q1; r = r1;
}

hp_uint& hp_uint::operator/=(const hp_uint& rhs)
{
  if (rhs.digits.size() == 1 && rhs.digits[0] == 0)
    return *this;

  hp_uint q, r;

  div_and_mod(q, r, *this, rhs);

  *this = q;

  return *this;
}

hp_uint& hp_uint::operator%=(const hp_uint& rhs)
{
  hp_uint q, r;

  div_and_mod(q, r, *this, rhs);

  *this = r;

  return *this;
}

const hp_uint hp_uint::operator/(const hp_uint& rhs) const
{
  return hp_uint(*this) /= rhs;
}

const hp_uint hp_uint::operator%(const hp_uint& rhs) const
{
  return hp_uint(*this) %= rhs;
}

}
