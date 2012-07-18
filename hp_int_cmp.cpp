#include "hpa.h"

namespace hpa
{

bool hp_int::operator<(const hp_int& rhs) const
{
  if (sign < rhs.sign)
    return true;
  else if (sign > rhs.sign)
    return false;

  if (digits.size() < rhs.digits.size())
    return true;
  else if (digits.size() > rhs.digits.size())
    return false;

  int i = digits.size() - 1;

  while (i >= 0 && digits[i] == rhs.digits[i])
    i--;
  
  if (i == -1)
    return false;
  else
    return digits[i] < rhs.digits[i];
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
    return true;
  else if (digits.size() > rhs.digits.size())
    return false;

  int i = digits.size() - 1;

  while (i >= 0 && digits[i] == rhs.digits[i])
    i--;

  if (i == -1)
    return true;
  else
    return digits[i] < rhs.digits[i];
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

  if (digits.size() != rhs.digits.size())
    return false;

  int i = 0;

  while (i < digits.size())
    if (digits[i] != rhs.digits[i++])
      break;

  return i == digits.size();
}

}
