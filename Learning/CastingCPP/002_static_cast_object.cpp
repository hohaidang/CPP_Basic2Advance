#include <iostream>
using namespace std;

class AnyMsg {};
class Base {};
class Derived : public Base {};
// class Derived : private Base {};
int main() {
  Derived d1;
  Base *b1 = (Base *)(&d1); // allowed
  Base *b2 =
      static_cast<Base *>(&d1); // neu Derive ma inherit tu Base voi private
                                // thi static_cast se bao loi
  return 0;
}
