#ifndef _HPA
#define _HPA

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
  void set_base(usint);
  void from_string(std::string);
  std::string to_string();
  hp_int operator+(hp_int);
  hp_int operator-(hp_int);
  hp_int operator*(hp_int);
  hp_int operator/(hp_int);
  hp_int operator%(hp_int);
  hp_int operator^(hp_int);
};

}

#endif
