#include "main.hpp"

void StringComparision(size_t size) {
  std::string s1(size, '-');
  std::string s2(size, '-');
  s1.compare(s2);
}

unsigned long Increment(unsigned long n) {
  unsigned long sum = 0;
  for(unsigned long i = 0; i < n; ++i) {
    sum++;
  }
  return sum;
}