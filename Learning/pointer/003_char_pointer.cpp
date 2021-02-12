#include <iostream>
#include <stdint.h>
#include <string.h>

// pointer la 1 bien int, bien int nay se chua dia chi cua 1 vung nho khac
// tuy vao hdh 32bit hoac 64bit ma bien int nay se co 4 byte hoac 8 byte dia chi

int main() {
  char *str1 = "HelloWorld";
  char str2[] = "HelloWorld";

  // str1 va str2 la khac nhau
  // str1: co 1 vung nho static unname = "HelloWorld", va tro con tro str1 vao
  // vung nho do str1[0] = '3'; // invalid boi vi vung nho unname nay la khong
  // thay doi duoc

  // str2: tao mot vung nho co gia tri "HelloWorld\n" sau do copy vao trong
  // stack, va con tro str2 se tro den vung stack do str2[0] = '3'; // cai nay
  // valid, boi vi vung nho nam tren stack thay doi duoc
  system("pause");
  return 0;
}
