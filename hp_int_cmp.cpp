#include "hpa.h"

namespace hpa
{

bool hp_int::cmp_abs_ge(const hp_int& a, const hp_int& b)
{
  if (a.digits.size() > b.digits.size())
    return true;
  else if (a.digits.size() < b.digits.size())
    return false;

  int i = a.digits.size() - 1;

  while (i >= 0 && a.digits[i] == b.digits[i])
    i--;

  if (i == -1)
    return true;
  else return a.digits[i] > b.digits[i];
}

bool hp_int::operator<(const hp_int& rhs) const
{
  if (sign < rhs.sign)
    return true;
  else if (sign > rhs.sign)
    return false;

  if (digits.size() < rhs.digits.size())
    if (sign == positive)
      return true;
    else
      return false;
  else if (digits.size() > rhs.digits.size())
    if (sign == positive)
      return false;
    else
      return true;

  int i = digits.size() - 1;

  while (i >= 0 && digits[i] == rhs.digits[i])
    i--;
  
  if (i == -1)
    return false;
  else
    if (sign == positive)
      return digits[i] < rhs.digits[i];
    else
      return digits[i] > rhs.digits[i];
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

  if (digits.size() < rhs.digits.size())
    if (sign == positive)
      return true;
    else
      return false;
  else if (digits.size() > rhs.digits.size())
    if (sign == positive)
      return false;
    else
      return true;

  int i = digits.size() - 1;

  while (i >= 0 && digits[i] == rhs.digits[i])
    i--;

  if (i == -1)
    return true;
  else
    if (sign == positive)
      return digits[i] < rhs.digits[i];
    else
      return digits[i] > rhs.digits[i];
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

  if (sign == 0)
    return true;

  if (digits.size() != rhs.digits.size())
    return false;

  int i = 0;

  while (i < digits.size())
    if (digits[i] != rhs.digits[i++])
      return false;

  return true;
}

}
