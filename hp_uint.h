#ifndef _HP_UINT
#define _HP_UINT

#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace hpa
{

typedef unsigned short usint;
typedef unsigned long ulint;

const usint USINT_MAX = std::numeric_limits<usint>::max();

// High precision unsigned integer
class hp_uint {
  usint base; // The base in which the output is displayed the input expected
  std::vector<usint> digits; // Digits internally stored in base 2^sizeof(usint)

  // Multiplication algorithms
  void grade_school(hp_uint&, const hp_uint&, const hp_uint&);

public:

  // Default constructor
  hp_uint();

  // String constructor
  hp_uint(std::string);

  // Sets the working base
  void set_base(usint);

  // Creates hp_uint from std::string
  void from_string(std::string);

  // Creates a std::string from hp_uint
  std::string to_string();

  // Functions for I/O
  friend std::ostream& operator<<(std::ostream&, const hp_uint&);
  friend std::istream& operator>>(std::istream&, hp_uint&);

  // Comparison operators
  bool operator<(const hp_uint&) const;
  bool operator>(const hp_uint&) const;
  bool operator<=(const hp_uint&) const;
  bool operator>=(const hp_uint&) const;
  bool operator!=(const hp_uint&) const;
  bool operator==(const hp_uint&) const;

  // Aassignment operator
  hp_uint& operator=(const hp_uint&);
  
  // Compound assignment operators
  hp_uint& operator+=(const hp_uint&);
  hp_uint& operator-=(const hp_uint&);
  hp_uint& operator*=(const hp_uint&);
  hp_uint& operator/=(const hp_uint&);
  hp_uint& operator%=(const hp_uint&);
  hp_uint& operator^=(const hp_uint&);

  // Binary arithmetic operators
  const hp_uint operator+(const hp_uint&) const;
  const hp_uint operator-(const hp_uint&) const;
  const hp_uint operator*(const hp_uint&) const;
  const hp_uint operator/(const hp_uint&) const;
  const hp_uint operator%(const hp_uint&) const;
  const hp_uint operator^(const hp_uint&) const;
};

}

#endif
