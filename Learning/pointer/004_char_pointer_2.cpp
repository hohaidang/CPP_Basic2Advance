#include <iostream>
#include <stdint.h>
#include <string.h>

// pointer la 1 bien int, bien int nay se chua dia chi cua 1 vung nho khac
// tuy vao hdh 32bit hoac 64bit ma bien int nay se co 4 byte hoac 8 byte dia chi

int main() {
  char str[10];
  std::cout << "no casting char = " << str << std::endl;
  std::cout << "cast to int = " << std::hex << (int)str << std::endl;

  // tai sao lai co su khac nhau?
  // str thi compiler se hieu la print gia tri cua con tro str,
  // nhung khong, compiler luon hieu va xu ly char* la mot kieu string
  // do do compiler se khong in ra dia chi cua con tro str, ma thay vao do in ra
  // gia tri cua con tro str ma gia tri nay chua duoc initial, nen no ra gia tri
  // rac

  // (int)str, neu ta cast ve integer, compiler se hieu la print gia tri cua con
  // tro str ma gia tri cua con tro str chinh la dia chi cua str[0]
  system("pause");
  return 0;
}
