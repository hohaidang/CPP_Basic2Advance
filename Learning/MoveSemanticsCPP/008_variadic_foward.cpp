#include <iostream>

// variadic forward, dung de tao 1 lop class wrap lop class da co

template <typename MsgBase> struct A : MsgBase {
  template <typename... Args>
  A(Args &&...args)
      : MsgBase(std::forward<Args>(args)...) {
  } // truyen vao bao nhieu input tuy y
    // tat ca parameter se duoc paste cho class MsgBase
};

template <typename A> struct Base {
  typedef A Array;

public:
  // so luong input truyen vao cua struct A tuy thuoc vao so luong input
  // constructor cua Base
  Base(Array array, A a1, A a2) : array(array) {}
  Array array;
  Array a1;
  Array a2;
};

int main() {
  A<Base<int>> dang(5, 6, 7); // truyen vao 3 input
  return 0;
}