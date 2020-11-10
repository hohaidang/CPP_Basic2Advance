#include <main.hpp>
#include "build/TutorialConfig.hpp" // This File will be create after cmake
// #include "square.hpp"

#ifdef USE_MATHLIB
#include "square.hpp" // khong can quan tam den folder
#endif

int main() {
  std::cout << "project version: " << Tutorial_VERSION_MAJOR << "."
            << Tutorial_VERSION_MINOR << '\n';

  dang_class my_class(5);
  std::cout << "my_class.var = " << my_class.val() << '\n';

#ifdef USE_MATHLIB
  double a = 10;
  std::cout << "square of a = " << square(a) << '\n';
#endif

  return 0;
}