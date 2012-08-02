#include <algorithm>
#include "hp_uint.h"

using namespace std;

namespace hpa
{

void hp_uint::grade_school(hp_uint& x, const hp_uint& a, const hp_uint& b)
{
  for (int i = 0; i < b.digits.size(); i++) {
    hp_uint row;
    ulint carry = 0, tmp;
    for (int j = 0; j < i; j++)
      row.digits.push_back(0);
    for (int j = 0; j < a.digits.size(); j++) {
      tmp = ((ulint) a.digits[j]) * ((ulint) b.digits[i]) + carry;
      carry = (ulint) tmp/(USINT_MAX + 1);
      row.digits[j+i] = (usint) tmp % (USINT_MAX + 1);
      row.digits.push_back(0);
    }
    int last = row.digits.size() - 1;
    row.digits[last] = carry;
    for (int k = last; row.digits[k] == 0 && k > 0; k--)
      row.digits.pop_back();
    x += row;
  }
}

hp_uint& hp_uint::operator*=(const hp_uint& rhs)
{
  hp_uint x;

  if (digits.size() >= rhs.digits.size())
    grade_school(x, *this, rhs);
  else
    grade_school(x, rhs, *this);

  *this = x;

  return *this;
}

const hp_uint hp_uint::operator*(const hp_uint& rhs) const
{
  return hp_uint(*this) *= rhs;
}

}
