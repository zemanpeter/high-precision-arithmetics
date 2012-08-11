#include "hp_uint.h"

using namespace std;

namespace hpa
{

hp_uint hp_uint::exp(hp_uint& a, hp_uint& b)
{
  if (b.digits.size() == 1 && b.digits[0] == 1)
    return a;

  hp_uint r;

  bool b_is_odd = false;
  if (b.digits[0] % 2 == 1)
    b_is_odd = true;

  r = a * a;
  b.divide_by_two();

  return exp(r, b) * (b_is_odd ? a : hp_uint("1"));
}

hp_uint& hp_uint::operator^=(const hp_uint& rhs)
{
  if ((rhs.digits.size() == 1 && rhs.digits[0] == 0) ||
      (digits.size() == 1 && digits[0] == 1)) {
    *this = hp_uint("1");
    return *this;
  }

  hp_uint a = *this, b = rhs;

  *this = exp(a, b);

  return *this;
}

const hp_uint hp_uint::operator^(const hp_uint& rhs) const
{
  return (hp_uint(*this) ^= rhs);
}

void hp_uint::divide_by_two()
{
  hp_uint ad2;
  ad2.digits[0] = digits[0]/2;
  if (digits.size() > 1) {
    ulint carry = 0;
    for (int i = 1; i < digits.size(); i++) {
      ulint tmp = ((ulint) digits[i]) * ((USINT_MAX+1)/2) + ((ulint) ad2.digits[i-1]) + carry;
      ad2.digits[i-1] = (usint) tmp % (USINT_MAX+1);
      carry = tmp/(USINT_MAX+1);
      ad2.digits.push_back(0);
    }
    if (carry > 0)
      ad2.digits[ad2.digits.size()-1] = carry;
    else
      ad2.digits.pop_back();
  }
  *this = ad2;
}

}
