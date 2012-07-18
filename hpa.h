#ifndef _HPA
#define _HPA

#include <iostream>
#include <string>
#include <vector>

namespace hpa
{

typedef unsigned short usint;
typedef unsigned long ulint;

// Type rapresenting sing of the hp_int
enum sign_t {
  positive = 1,
  zero = 0,
  negative = -1
};

// High precision integer
class hp_int {
  usint base; // The base in which the output is displayed the input expected
  sign_t sign; // Sing of the number
  std::vector<usint> digits; // Digits internally stored in base 2^sizeof(usint)
public:
  // Default constructor
  hp_int();

  // String constructor
  hp_int(std::string);

  // Sets the working base
  void set_base(usint);

  // Creates hp_int from std::string
  void from_string(std::string);

  // Creates a std::string from hp_int
  std::string to_string();

  // Functions for I/O
  friend std::ostream& operator<<(std::ostream& os, hp_int& hi);
  friend std::istream& operator>>(std::istream& is, hp_int& hi);

  // Comparison operators
  bool operator<(const hp_int&) const;
  bool operator>(const hp_int&) const;
  bool operator<=(const hp_int&) const;
  bool operator>=(const hp_int&) const;
  bool operator!=(const hp_int&) const;
  bool operator==(const hp_int&) const;

  // Compound assignment operators
  hp_int& operator=(const hp_int&);
  hp_int& operator+=(const hp_int&);
  hp_int& operator-=(const hp_int&);
  hp_int& operator*=(const hp_int&);
  hp_int& operator/=(const hp_int&);
  hp_int& operator%=(const hp_int&);
  hp_int& operator^=(const hp_int&);

  // Binary arithmetic operators
  const hp_int operator+(const hp_int&) const;
  const hp_int operator-(const hp_int&) const;
  const hp_int operator*(const hp_int&) const;
  const hp_int operator/(const hp_int&) const;
  const hp_int operator%(const hp_int&) const;
  const hp_int operator^(const hp_int&) const;
};

}

#endif
