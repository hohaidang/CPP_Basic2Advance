#include <iostream>
#include <string.h>

uintptr_t str2[2]; // unsigned long int
// uintptr thuong dung lam bien de chua dia chi
// voi system 32-bit thi sizeof(uintptr_t) = 4 bytes
//     system 64-bit thi sizeof(uintptr_t) = 8 bytes

// #define CACH2

int main() {
  std::cout << "sizeof(uintptr_t) = " << sizeof(uintptr_t) << std::endl;

  char temp2[] = "123456789";

#ifdef CACH2
  char *newData;
  str2[0] = (uintptr_t)(newData = (char *)malloc(strlen(temp2) * sizeof(char)));
  memcpy(newData, temp2, strlen(temp2));
#elif CACH3
  str2[0] = (uintptr_t)((char *)malloc(strlen(temp2) * sizeof(char)));
  memcpy((char *)str2[0], temp2, strlen(temp2));
#else
  str2[0] = (uintptr_t)((char *)new char[strlen(temp2) * sizeof(char)]);
  memcpy((char *)str2[0], temp2, strlen(temp2));
  // str2[0] chinh la dia chi vung nho
  // nen ta phai cast ve (char *) de bo vao con tro trong ham memcpy
#endif

  // o day str[2] se chua dia tri cua vung nho, chu khong phai chua gia tri nua
  // malloc se tra ve dia tri cua vung nho moi khoi tao, sau do ep kieu ve con
  // tro char roi ep kieu ve unsigned long int de bien dia chi thanh 1 so 32-bit
  // hoac 64bit roi gan vao str2[0]
  std::cout << "str2 = " << (char *)str2[0] << std::endl;
  delete[](char *) str2[0];
  return 0;
}