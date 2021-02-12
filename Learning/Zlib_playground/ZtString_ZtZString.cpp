#include <ZtString.hpp>
#include <iostream>

// ZtZString la non-copy string
ZtZString func() {
  char myword[] = {"Hello"};
  return myword; // nen khi myword bi destroy, thi bar se la invalid
}

// ZtString la copy string
ZtString func1() {
  char myword[] = {"Hello"};
  return myword; // myword nay du bi destroy nhung foo van se van con, vi co
                 // vung nho rieng
}

// ZtZString se nhanh hon, nhung cung nguy hiem hon.
int main() {
  ZtZString bar = func();
  puts(bar);
  ZtString foo = func1();
  puts(foo);
  return 0;
}
