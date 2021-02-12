#include <iostream>
#include <stdint.h>
#include <string.h>

// pointer la 1 bien int, bien int nay se chua dia chi cua 1 vung nho khac
// tuy vao hdh 32bit hoac 64bit ma bien int nay se co 4 byte hoac 8 byte dia chi

int main() {
  char *buffer = new char[8]; // bien con tro buffer, chua dia chi dau tien cua
                              // vung nho char (size = 8)
  memset(buffer, 0, 8);
  char *ptr_1 = buffer; // bien con tro ptr_1 chua dia chi cua buffer
  // &buffer la con tro 2 chieu **char
  char **ptr_2 = &buffer;
  // ptr_2 la bien chua dia chi dau tien, trong dia chi dau tien se co gia tri
  // la dia chi thu 2 *ptr_2 la bien chua dia chi thu 2, gia tri cua dia chi thu
  // 2 se la char[8] duoc khoi tao o tren
  // **ptr_2 la gia tri cua dia chi thu 2.
  system("pause");
  return 0;
}
