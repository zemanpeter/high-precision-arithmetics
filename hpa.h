#ifndef _HPA
#define _HPA

#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace hpa
{

typedef unsigned short usint;
typedef unsigned long ulint;

const usint USINT_MAX = std::numeric_limits<usint>::max();

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

  // Comparison in absolute value
  bool cmp_abs_ge(const hp_int&, const hp_int&);

  // Internal addition function
  hp_int& addition(hp_int&, const hp_int&);

  // Internal substraction function
  hp_int& substraction(hp_int& const hp_int&);

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
  friend std::ostream& operator<<(std::ostream&, hp_int&);
  friend std::istream& operator>>(std::istream&, hp_int&);

  // Comparison operators
  bool operator<(const hp_int&) const;
  bool operator>(const hp_int&) const;
  bool operator<=(const hp_int&) const;
  bool operator>=(const hp_int&) const;
  bool operator!=(const hp_int&) const;
  bool operator==(const hp_int&) const;

  // Aassignment operator
  hp_int& operator=(const hp_int&);
  
  // Compound assignment operators
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
