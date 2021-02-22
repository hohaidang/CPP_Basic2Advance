#include <iostream>
using namespace std;

int main() {
  struct dat {
    short a, short b;
  };
  long value = 0xA224B118;
  data *pd = reinterpret_cast<dat *>(&value);
  cout << hex << pd->a;
  return 0;
}