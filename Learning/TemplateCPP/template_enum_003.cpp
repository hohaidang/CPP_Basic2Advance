#include <iomanip>
#include <iostream>
#include <type_traits>

enum dang { bien1 = 0, bien2 = 1 };

template <enum dang> class test_class {
public:
  test_class() {
    std::cout << "enum = ";
    std::cout << "HelloWorld";
  }
};

enum Fruit {
  BANANA = 5,
};

template <typename E, E V> constexpr void func() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

enum my_enum { ALPHA = 15, BETA = 20 };

template <my_enum E> class Foo {
  // ...
public:
  Foo() { std::cout << "Enum input = " << E << '\n'; }
};

int main() {
  func<Fruit, (Fruit)5>();
  func<Fruit, (Fruit)10>();
  Foo<BETA> dang;
  Foo<ALPHA> duc;
  return 0;
}
