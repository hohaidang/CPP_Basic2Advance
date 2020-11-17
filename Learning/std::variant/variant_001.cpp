#include <iostream>
#include <string>
#include <variant>

// variant cung giong nhu union. Trong mot thoi diem chi co 1 kieu du lieu duoc
// active nhung variant co typesafety, no se khong cho phep get value cua type
// nao do neu type do hien tai khong duoc activate

struct SamepleVisitor {
  void operator()(int i) const { std::cout << "int: " << i << "\n"; }
  void operator()(float f) const { std::cout << "float: " << f << "\n"; }
  void operator()(const std::string &s) const {
    std::cout << "string: " << s << "\n";
  }
};

int main() {
  std::variant<int, float, std::string> intFloatString;
  static_assert(std::variant_size_v<decltype(intFloatString)> == 3);

  std::cout << "index = " << intFloatString.index() << '\n';
  intFloatString = 100.0f; // auto change to float
  std::cout << "index = " << intFloatString.index() << '\n';
  intFloatString = "hello super world"; // auto change to string
  std::cout << "index = " << intFloatString.index() << '\n';

  // ----try with get_if -----
  // if current variant type is int
  if (const auto intPtr(std::get_if<int>(&intFloatString)); intPtr) {
    std::cout << "std::variant activated in int! val=" << *intPtr << '\n';
  } else if (const auto floatPtr(std::get_if<float>(&intFloatString));
             floatPtr) {
    std::cout << "std::variant activated in float! val=" << *floatPtr << '\n';
  } else if (const auto stringPtr(std::get_if<std::string>(&intFloatString));
             stringPtr) {
    std::cout << "std::variant activated in String! val=" << *stringPtr << '\n';
  }
  // -------------------------
  // ----- Another way to get current activated holds_alternative---------
  if (std::holds_alternative<int>(intFloatString)) {
    std::cout << "std::variant activated in int!\n";
  } else if (std::holds_alternative<float>(intFloatString)) {
    std::cout << "std::variant activated in float!\n";
  } else if (std::holds_alternative<std::string>(intFloatString)) {
    std::cout << "std::variant activated in String!\n";
  }
  // ---------------------------------------------------------------------

  // try/catch if current variant is not expected.
  try {
    auto f = std::get<float>(intFloatString);
    std::cout << "float! " << f << "\n";
  } catch (std::bad_variant_access &) {
    std::cout << "our variant doesn't hold float at this moment...\n";
  }

  // visit: se pass gia tri hien tai cua variant vao constructor() cua struct
  // SampleVisitor
  std::visit(SamepleVisitor{}, intFloatString);
  intFloatString = 10;
  std::visit(SamepleVisitor{}, intFloatString);
  intFloatString = 10.0f;
  std::visit(SamepleVisitor{}, intFloatString);
  return 0;
}