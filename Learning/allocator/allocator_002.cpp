// TestCPP1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <memory>

struct mystruct {
  int a = 5;
};

int main() {
  mystruct *ptr = nullptr;
  ptr = new mystruct;
  new (ptr) mystruct[2]; // allocate them 2 vung nho moi (tinh luon ca vung nho
                         // allocate san) thi se chi co 1 vung nho moi
  return 0;
}