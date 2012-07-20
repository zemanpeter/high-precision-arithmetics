#include "hp_uint.h"

namespace hpa
{

bool hp_uint::operator<(const hp_uint& rhs) const
{
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

bool hp_uint::operator>(const hp_uint& rhs) const
{
  return !(*this <= rhs);
}

bool hp_uint::operator<=(const hp_uint& rhs) const
{
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

bool hp_uint::operator>=(const hp_uint& rhs) const
{
  return !(*this < rhs);
}

bool hp_uint::operator!=(const hp_uint& rhs) const
{
  return !(*this == rhs);
}

bool hp_uint::operator==(const hp_uint& rhs) const
{
  if (digits.size() != rhs.digits.size())
    return false;

  int i = 0;

  while (i < digits.size())
    if (digits[i] != rhs.digits[i++])
      return false;

  return true;
}

}
