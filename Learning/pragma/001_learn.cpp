#include <iostream>
#include <stddef.h>

// pragma pack khong cho compiler add padding byte vao

#pragma pack(push, 1)
struct MsgBase {
  char evenType;
  char equalSize;
  char seperator;
};

template <int field> struct my_struct {
  static constexpr int field_ =
      field; // nam o vung nho const, khong nam trong stack
};

struct B : MsgBase {
  char data = 5;
  my_struct<5> myStruct;
  char data2 = '3';
};
#pragma pack(pop)

int main() {
  // o day neu nhu khong co pragma pack thi struct MsgBase se tu dong add
  // padding byte vao nen offsetof(data) = 4 thay vi la 3
  std::cout << "offset = " << offsetof(B, data) << std::endl;
  std::cout << "myStruct offset = " << offsetof(B, myStruct) << std::endl;
  std::cout << "data2 offset = " << offsetof(B, data2) << std::endl;
  // o day ta thay data2 = 5 co nghia la phan static constexpr int khong nam
  // trong vung nho stack cua my_struct ma no nam trong vung nho const. Neu nhu
  // bo static constexpr thi data2 offset = 8
  return 0;
}