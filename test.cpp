#include <iostream>
#include "hpa.h"

using namespace std;
using namespace hpa;

int main()
{
  hp_int a, b;
  while (cin >> a >> b) {
    if (b != hp_int("0"))
      cout << (a^b) << endl;
  }
  return 0;
}
