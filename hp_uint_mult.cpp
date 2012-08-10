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

hp_uint hp_uint::karatsuba(const hp_uint& a, const hp_uint& b)
{
  int n = a.digits.size();
  int m = b.digits.size();
  int maxnm = max(n, m);

  if (maxnm < 50) {
    hp_uint p;
    if (a.digits.size() >= b.digits.size()) grade_school(p, a, b);
    else grade_school(p, b, a);
    return p;
  }

  hp_uint al, ar, bl, br;
  ar.digits[0] = a.digits[0];
  br.digits[0] = b.digits[0];
  for (int i = 1; i < maxnm/2; i++) {
    if (i < n) ar.digits.push_back(a.digits[i]);
    if (i < m) br.digits.push_back(b.digits[i]);
  }
  if (maxnm/2 < n) al.digits[0] = a.digits[maxnm/2];
  if (maxnm/2 < m) bl.digits[0] = b.digits[maxnm/2];
  for (int i = maxnm/2 + 1; i < maxnm; i++) {
    if (i < n) al.digits.push_back(a.digits[i]);
    if (i < m) bl.digits.push_back(b.digits[i]);
  }

  hp_uint p1 = karatsuba(al, bl);
  hp_uint p2 = karatsuba(ar, br);
  hp_uint p3 = karatsuba(al + ar, bl + br);
  hp_uint t1 = p3 - p1 - p2;

  for (int i = 0; i < ((int) maxnm/2)*2; i++) {
    if (i < ((int) maxnm/2)) t1.digits.push_back(0);
    p1.digits.push_back(0);
  }
  for (int i = p1.digits.size() - 1; i >= 0; i--)
    if (i-((int) (maxnm/2))*2 >= 0) p1.digits[i] = p1.digits[i-((int) (maxnm/2))*2];
    else p1.digits[i] = 0;
  for (int i = t1.digits.size() - 1; i >= 0; i--)
    if (i-((int) maxnm/2) >= 0) t1.digits[i] = t1.digits[i-((int) maxnm/2)];
    else t1.digits[i] = 0;
  
  return p1 + t1 + p2;
}

hp_uint& hp_uint::operator*=(const hp_uint& rhs)
{
  *this = karatsuba(*this, rhs);

  return *this;
}

const hp_uint hp_uint::operator*(const hp_uint& rhs) const
{
  return hp_uint(*this) *= rhs;
}

}
