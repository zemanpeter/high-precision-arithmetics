#include "hp_uint.h"

using namespace std;

namespace hpa
{

hp_uint& hp_uint::operator+=(const hp_uint& rhs)
{
  int i;
  ulint tmp, carry = 0;
  
  for (i = 0; i < rhs.digits.size(); i++) {
    if (i >= digits.size())
      digits.push_back(0);

    tmp = (ulint) (digits[i] + rhs.digits[i] + carry);
    if (tmp > USINT_MAX)
      carry = 1;
    else
      carry = 0;
    digits[i] = (usint) tmp;
  }

  if (carry == 1)
    if (i == digits.size())
      digits.push_back(1);
    else
      digits[i] += 1;

  return *this;
}

hp_uint& hp_uint::operator-=(const hp_uint& rhs)
{
  int i;
  ulint tmp, carry = 0;

  for (i = 0; i < rhs.digits.size(); i++) {
    tmp = (ulint) (digits[i] - carry - rhs.digits[i] + (USINT_MAX + 1));
    if (tmp <= USINT_MAX)
      carry = 1;
    else
      carry = 0;
    digits[i] = (tmp);
  }

  if (carry == 1)
    digits[i]--;

  for (int k = digits.size() - 1; digits[k] == 0 && k > 0; k--)
    digits.pop_back();

  return *this;
}

const hp_uint hp_uint::operator+(const hp_uint& rhs) const
{
  return hp_uint(*this) += rhs;
}

const hp_uint hp_uint::operator-(const hp_uint& rhs) const
{
  return hp_uint(*this) -= rhs;
}

}
