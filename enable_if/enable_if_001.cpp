#include <iomanip>
#include <iostream>
#include <type_traits>

class foo;
class bar;

template <class T> struct is_bar {
  template <class Q = T>
  typename std::enable_if<std::is_same<Q, bar>::value, bool>::type check() {
    // kiem tra neu type cua struct la "bar" thi tra ve true
    return true;
  }

  template <class Q = T>
  typename std::enable_if<!std::is_same<Q, bar>::value, bool>::type check() {
    // kiem tra neu type cua struct khong phai "bar" thi tra ve true
    return false;
  }
};

int main() {
  is_bar<foo> foo_is_bar;
  is_bar<bar> bar_is_bar;
  std::cout << std::boolalpha;
  std::cout << "foo_is_bar return " << foo_is_bar.check() << '\n';
  std::cout << "bar_is_bar return " << bar_is_bar.check() << '\n';
  return 0;
}
