#include "hp_uint.h"

using namespace std;

namespace hpa
{

hp_uint::hp_uint()
{
  base = 10;
  digits.push_back(0);
}

hp_uint::hp_uint(string s)
{
  base = 10;
  this->from_string(s);
}

void hp_uint::set_base(usint b)
{
  if (2 <= b && b <= 36)
    base = b;
}

void hp_uint::from_string(string s)
{
  // Clear current digits
  digits.clear();

  // Ingnore trailing zeroes
  int i = 0;

  while (i < s.size() && s[i] == '0')
    i++;
  if (i == s.size()) {
    // The number is zero
    digits.push_back(0);
    return;
  }

  // Process the string
  for (i; i < s.size(); i++) {
    usint digit;

    if ('0' <= s[i] && s[i] <= '9')
      digit = s[i] - '0';
    else
      digit = s[i] - 'a' + 10;

    ulint carry = 0, tmp;

    // Multiply the current number by 'base'
    digits.push_back(0);
    for (int j = 0; j < digits.size(); j++) {
      tmp = (ulint) digits[j];
      tmp = tmp * ((ulint) base) + carry;
      digits[j] = (usint) tmp;
      carry = (tmp >> ((ulint) (sizeof(usint) * 8)));
    }

    // To the current number add 'digit'
    carry = 0;
    digits.push_back(0);
    tmp = (ulint) digits[0];
    tmp += (ulint) digit;
    digits[0] = (usint) tmp;
    carry = (tmp >> ((ulint) (sizeof(usint) * 8)));

    int j = 1;

    while (carry > 0) {
      tmp = (ulint) digits[j];
      tmp += carry;
      digits[j] = (usint) tmp;
      carry = (tmp >> ((ulint) (sizeof(usint) * 8)));
      j++;
    }

    // Clear leading zeroes
    for (int k = digits.size() - 1; digits[k] == 0; k--)
      digits.pop_back();
  }
}

string hp_uint::to_string()
{
  if (digits[0] == 0 && digits.size() == 1)
    return "0";

  string rs;
  vector<usint> digits_copy = digits;

  // Process the number
  while (!(digits_copy[0] == 0 && digits_copy.size() == 1)) {
    ulint carry = 0;

    // New digit will be stored in carry
    for (int i = digits_copy.size() - 1; i >= 0; i--) {
      ulint tmp = (carry * ((ulint) USINT_MAX + 1)) + ((ulint) digits_copy[i]);
      digits_copy[i] = (usint) (tmp / base);
      carry = (ulint) (tmp % base);
    }

    // Pop the created zeros
    for (int k = digits_copy.size() - 1; digits_copy[k] == 0 && k > 0; k--)
      digits_copy.pop_back();

    usint digit = (usint) carry;

    // Append the'/usr/share/applications/skype.desktop'  digit to the string
    if (0 <= digit && digit <= 9)
      rs.push_back('0' + digit);
    else
      rs.push_back('a' + digit - 10);
  }

  // Return it reversed
  return string(rs.rbegin(), rs.rend());
}

ostream& operator<<(ostream& os, const hp_uint& rhs)
{
  string s;
  
  s = rhs.to_string();
  os << s;

  return os;
}

istream& operator>>(istream& is, hp_uint& rhs)
{
  string s;

  is >> s;
  rhs.from_string(s);

  return is;
}

hp_uint& hp_uint::operator=(const hp_uint& rhs)
{
  if (this != &rhs)
    digits = rhs.digits;

  return *this;
}

bool hp_uint::is_even()
{
  if (digits[0] % 2 == 0)
    return true;
  else
    return false;
}

bool hp_uint::is_zero()
{
  if (digits.size() == 1 && digits[0] == 0)
    return true;
  else
    return false;
}

}
