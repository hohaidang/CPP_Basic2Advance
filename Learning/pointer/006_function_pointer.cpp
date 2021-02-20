#include <iostream>

void printfData(int a) { printf("HelloWorld, a = %d\n", a); }

void consider(bool in, void (*ptr)(int)) {
  if (in) {
    (*ptr)(5);
  } else {
    printf("Nothing to print\n");
  }
}

template <typename fn> void considerCPP(bool in, fn functionPrint) {
  // functionPrint se la kieu con tro void(*)(int)
  if (in) {
    functionPrint(5); // tuong duong *functionPrint(5);
  } else {
    printf("Nothing to print\n");
  }
}

int main() {
  void (*ptr)(int) = &printfData;
  // (*ptr)();
  consider(true, ptr);
  consider(false, ptr);
  considerCPP(true, ptr);

  consider(true, &printfData);
  consider(false, &printfData);
  considerCPP(true, &printfData);
  return 0;
}