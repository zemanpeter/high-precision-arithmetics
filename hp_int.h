#include "hp_uint.h"

namespace hpa
{

enum sign_t {
  positive = 1,
  negative = -1
};

class hp_int {

  sign_t sign;
  hp_uint absv;

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

  // Returns true if the number is even
  bool is_even();

  // Functions for I/O
  friend std::ostream& operator<<(std::ostream&, const hp_int&);
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
