#include <iostream>
#include <vector>

using namespace std;

#include "hp_uint.h"

using namespace hpa;

int main()
{
  hp_uint a, b;
  while (cin >> a >> b) {
    cout << a * b << endl; 
  }
  return 0;
}
