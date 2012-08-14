#include "hp_int.h"

using namespace std;

namespace hpa
{

hp_int::hp_int()
{
  sign = positive;
}

hp_int::hp_int(string s)
{
  sign = positive;
  from_string(s);
}

void hp_int::set_base(usint b)
{
  absv.set_base(b);
}

void hp_int::from_string(string s)
{
  sign = positive;
  if (s[0] == '-') {
    sign = negative;
    absv.from_string(s.substr(1));
  }
  else
    absv.from_string(s);

  if (absv.is_zero())
    sign = positive;
}

string hp_int::to_string()
{
  if (sign == negative)
    return '-' + absv.to_string();
  else
    return absv.to_string();
}

bool hp_int::is_even()
{
  if (absv.is_even())
    return true;
  else
    return false;
}

ostream& operator<<(ostream& os, const hp_int& rhs)
{
  string s;

  s = rhs.to_string();
  os << s;

  return os;
}

istream& operator>>(istream& is, hp_int& rhs)
{
  string s;

  is >> s;
  rhs.from_string(s);

  return is;
}

hp_int& hp_int::operator=(const hp_int& rhs)
{
  if (this != &rhs) {
    sign = rhs.sign;
    absv = rhs.absv;
  }

  return *this;
}

hp_int& hp_int::operator+=(const hp_int& rhs)
{
  if (sign == rhs.sign)
    absv = absv + rhs.absv;
  else
    if (sign == negative)
      if (rhs.absv >= absv) {
        absv = rhs.absv - absv;
        sign = positive;
      }
      else
        absv = absv - rhs.absv;
    else
      if (absv >= rhs.absv)
        absv = absv - rhs.absv;
      else {
        absv = rhs.absv - absv;
        sign = negative;
      }

  if (absv.is_zero())
    sign = positive;

  return *this;
}

const hp_int hp_int::operator+(const hp_int& rhs) const
{
  return hp_int(*this) += rhs;
}

hp_int& hp_int::operator-=(const hp_int& rhs)
{
  if (sign + rhs.sign == 0)
    absv = absv + rhs.absv;
  else
    if (sign == negative)
      if (rhs.absv >= absv) {
        absv = rhs.absv - absv;
        sign = positive;
      }
      else
        absv = absv - rhs.absv;
    else
      if (absv >= rhs.absv)
        absv = absv - rhs.absv;
      else {
        absv = rhs.absv - absv;
        sign = negative;
      }

  if (absv.is_zero())
    sign = positive;

  return *this;
}

const hp_int hp_int::operator-(const hp_int& rhs) const
{
  return hp_int(*this) -= rhs;
}

hp_int& hp_int::operator*=(const hp_int& rhs)
{
  if (sign * rhs.sign == 1)
    sign = positive;
  else
    sign = negative;
  absv = absv * rhs.absv;

  if (absv.is_zero())
    sign = positive;

  return *this;
}

const hp_int hp_int::operator*(const hp_int& rhs) const
{
  return hp_int(*this) *= rhs;
}

hp_int& hp_int::operator/=(const hp_int& rhs)
{
  if (sign * rhs.sign == 1)
    sign = positive;
  else
    sign = negative;
  absv = absv / rhs.absv;

  if (absv.is_zero())
    sign = positive;

  return *this;
}

const hp_int hp_int::operator/(const hp_int& rhs) const
{
  return hp_int(*this) /= rhs;
}

hp_int& hp_int::operator%=(const hp_int& rhs)
{
  sign = positive;
  absv = absv % rhs.absv;

  return *this;
}

const hp_int hp_int::operator%(const hp_int& rhs) const
{
  return hp_int(*this) %= rhs;
}

hp_int& hp_int::operator^=(const hp_int& rhs)
{
  if (rhs.sign == negative) {
    sign = positive;
    absv = hp_uint("0");
    return *this;
  }
  
  if (sign == negative)
    if (rhs.is_even())
      sign = positive;
    else negative;

  absv = (absv^rhs.absv);

  return *this;
}

const hp_int hp_int::operator^(const hp_int& rhs) const
{
  return (hp_int(*this) ^= rhs);
}

bool hp_int::operator<(const hp_int& rhs) const
{
  if (sign < rhs.sign)
    return true;
  else if (sign > rhs.sign)
    return false;
  else
    if (sign == positive)
      return absv < rhs.absv;
    else
      return absv > rhs.absv;
}

bool hp_int::operator>(const hp_int& rhs) const
{
  return !(*this <= rhs);
}

bool hp_int::operator<=(const hp_int& rhs) const
{
  if (sign < rhs.sign)
    return true;
  else if (sign > rhs.sign)
    return false;
  else
    if (sign == positive)
      return absv <= rhs.absv;
    else
      return absv >= rhs.absv;
}

bool hp_int::operator>=(const hp_int& rhs) const
{
  return !(*this < rhs);
}

bool hp_int::operator!=(const hp_int& rhs) const
{
  return !(*this == rhs);
}

bool hp_int::operator==(const hp_int& rhs) const
{
  if (sign != rhs.sign)
    return false;
  else
    return absv == rhs.absv;
}

}
