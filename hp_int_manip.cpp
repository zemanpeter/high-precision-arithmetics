#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

#include "hpa.h"

namespace hpa
{

const usint USINT_MAX = numeric_limits<usint>::max();

hp_int::hp_int()
{
  base = 10;
  sign = zero;
  digits.push_back(0);
}

hp_int::hp_int(string s)
{
  base = 10;
  this->from_string(s);
}

void hp_int::set_base(usint b)
{
  if (2 <= b && b <= 36)
    base = b;
}

void hp_int::from_string(string s)
{
  // Clear current digits
  digits.clear();

  // Set sign
  if (s[0] == '-') {
    sign = negative;
    s.erase(s.begin());
  }
  else
    sign = positive;

  // Ingnore trailing zeroes
  int i = 0;

  while (i < s.size() && s[i] == '0')
    i++;
  if (i == s.size()) {
    // The number is zero
    sign = zero;
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

string hp_int::to_string()
{
  if (sign == zero)
    // The number is zero
    return "0";

  string rs;
  vector<usint> digits_copy = digits;

  // Process the number
  int a = 1;
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

  if (sign == negative)
    rs.push_back('-');

  // Return it reversed
  return string(rs.rbegin(), rs.rend());
}

ostream& operator<<(ostream& os, hp_int& hi)
{
  string s;
  s = hi.to_string();

  os << s;

  return os;
}

istream& operator>>(istream& is, hp_int& hi)
{
  string s;

  is >> s;
  hi.from_string(s);

  return is;
}

}
