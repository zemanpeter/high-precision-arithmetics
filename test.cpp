#include <iostream>
#include <vector>

using namespace std;

#include "hpa.h"

using namespace hpa;

int main()
{
  hp_int a;
  string s;
  cin >> s;
  a.from_string(s);
  s = a.to_string();
  cout << s << endl;
  return 0;
}
