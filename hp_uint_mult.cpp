#include <algorithm>
#include "hp_uint.h"

using namespace std;

namespace hpa
{

hp_uint& hp_uint::grade_school(hp_uint& a, const hp_uint& b)
{
  hp_uint *ap, *bp;

  if (a.digits.size() >= b.digits.size()) {
    ap = &a;
    bp = &b;
  }
  else {
    ap = &b;
    bp = &a;
  }

  vector<hp_uint> rows(bp->digits.size());

  for (int i = 0; i < bp->digits.size(); i++) {
    ulint tmp, carry = 0;
    for (int j = 0; j < i; j++)
      rows[i].digits.push_back(0);
    for (int j = 0; j < ap->digits.size(); j++) {
      tmp = ((ulint) ap->digits[j]) * ((ulint) bp->digits[i]) + carry;
      carry = (ulint) tmp/(USINT_MAX + 1);
      rows[i].digits[j+i] = (usint) tmp % (USINT_MAX + 1);
      rows[i].digits.push_back(0);
    }
    int last = rows[i].digits.size() - 1;
    rows[i].digits[last] = carry;
    for (int k = last; rows[i].digits[k] == 0 && k > 0; k--)
      rows[i].digits.pop_back();
  }

  for (int i = 1; i < rows.size(); i++)
    rows[i] += rows[i-1];
  a = rows[rows.size() - 1];

  return a;
}

hp_uint& hp_uint::operator*=(const hp_uint& rhs)
{
  grade_school(*this, rhs);

  return *this;
}

const hp_uint hp_uint::operator*(const hp_uint& rhs) const
{
  return hp_uint(*this) *= rhs;
}

}
