#include <iostream>
#include <stdint.h>
#include <string.h>

// pointer la 1 bien int, bien int nay se chua dia chi cua 1 vung nho khac
// tuy vao hdh 32bit hoac 64bit ma bien int nay se co 4 byte hoac 8 byte dia chi

int main() {
  void *v_ptr = 0; // co 1 bien int v_ptr co gia tri la 0
  int a = 5;
  int *ptr = &a; // ptr la 1 bien int chua dia chi cua a
  std::cout << "Gia tri cua bien ptr = " << ptr << std::endl;
  std::cout << "Gia tri cua vung nho ptr tro toi" << *ptr << std::endl;
  // &ptr quen cai nay di, cai nay la char**

  int ptr_[5] = {1, 2, 3, 4, 5};
  // &ptr_[0] == ptr_
  // &ptr_[1] == (ptr_ + 1)
  //  ptr_[0] == *ptr_
  //  ptr_[1] == *(ptr_ + 1)
  system("pause");
  return 0;
}