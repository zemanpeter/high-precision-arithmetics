#ifndef _HPA
#define _HPA

#include <iostream>
#include <string>
#include <vector>

namespace hpa
{

typedef unsigned short usint;
typedef unsigned long ulint;

enum sign_t {
  positive = 1,
  zero = 0,
  negative = -1
};

class hp_int {
  usint base;
  sign_t sign;
  std::vector<usint> digits;
public:
  hp_int();
  hp_int(std::string);
  void set_base(usint);
  void from_string(std::string);
  std::string to_string();
  friend std::ostream& operator<<(std::ostream& os, hp_int& hi);
  friend std::istream& operator>>(std::istream& is, hp_int& hi);
  bool operator<(const hp_int&) const;
  bool operator>(const hp_int&) const;
  bool operator<=(const hp_int&) const;
  bool operator>=(const hp_int&) const;
  bool operator!=(const hp_int&) const;
  bool operator==(const hp_int&) const;
  hp_int operator+(hp_int);
  hp_int operator-(hp_int);
  hp_int operator*(hp_int);
  hp_int operator/(hp_int);
  hp_int operator%(hp_int);
  hp_int operator^(hp_int);
};

}

#endif
