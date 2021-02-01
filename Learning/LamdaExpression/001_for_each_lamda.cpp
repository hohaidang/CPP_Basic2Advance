#include <iostream>
#include <vector>

void PrettyPrint(int a) { std::cout << "Value: " << a << '\n'; }

// truyen vao 1 function pointer
void ForEach(std::vector<int> &datas, void (*func)(int)) {
  for (auto data : datas)
    func(data);
}

template <typename funcIn>
void ForEach_template(
    std::vector<int> &datas,
    funcIn func) { // funcIn la function pointer su dung template
  for (auto data : datas)
    func(data);
}

template <typename funcIn> int Find_If(std::vector<int> &datas, funcIn func) {
  for (auto data : datas)
    if (func(data))
      return data;
  return 0;
}

int main() {
  std::vector<int> data = {1, 3, 5, 7};
  ForEach(data,
          PrettyPrint); // truyen dia chi ham PrettyPrint vao function pointer

  std::cout << "---------Lamda--------\n";
  // thay vi dung 1 function pointer tro vao ham PrettyPrint, ta co the thay the
  // ham PrettyPrint bang 1 lamda, anonimous function
  ForEach(data, [](int in) { // bien "in" nay se duoc thay bang "data" trong
                             // function ForEach() "func(data)"
    std::cout << "Value: " << in << '\n';
  });

  // cao cap hon thi ta se dung template cho function pointer
  std::cout << "---------Advance generic-------\n";
  ForEach_template(data, [](int in) { //
    std::cout << "Value: " << in << '\n';
  });

  std::cout << "-------Find_If-----------\n";
  // cho nay giong voi ham std::find_if
  // neu gap so lon hon >= 5 thi return
  auto result = Find_If(data, [](const auto &data) {
    return data >= 5;
  }); 
  std::cout << "result = " << result << '\n';
  return 0;
}
