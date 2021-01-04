#include <iostream>
#include <memory>

struct Type {
  int do_thing() const { return data + 4; };
  int data;
};

int main(int argc, char *argv[]) {
  if (argc > 1) {
    std::cout << "Ho Hai Dang";
  }
  Type obj;
  obj.do_thing();
  int b = 5;
  int a[5] = {1, 2, 3, 4, 5};
}