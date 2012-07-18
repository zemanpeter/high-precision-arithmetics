#include <iostream>
#include <vector>

using namespace std;

#include "hpa.h"

using namespace hpa;

int main()
{
  hp_int a, b;
  while (cin >> a >> b) {
    if (a < b)
      cout << "Prve je mensie." << endl;
    if (a <= b)
      cout << "Prve je mensie alebo rovne." << endl;
    if (a > b)
      cout << "Prve je vacsie." << endl;
    if (a >= b)
      cout << "Prve je vacsie alebo rovne." << endl;
    if (a != b)
      cout << "Nerovnaju sa." << endl;
    if (a == b)
      cout << "Rovnaju sa." << endl;
  }
  return 0;
}
