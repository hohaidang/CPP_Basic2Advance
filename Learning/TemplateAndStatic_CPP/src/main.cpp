/*
 * main.cpp
 *
 *  Created on: Jan 24, 2020
 *      Author: prnsoft
 */




#include <iostream>

using namespace std;

template <typename T>
void fun(const T& x)
{
  static int i = 10;
  cout << ++i;
  return;
}

int main()
{
//	cout << "Hello World";
  fun<int>(1);  // prints 11
  cout << endl;
  fun<int>(1);  // prints 12
  cout << endl;
  fun<double>(1.1); // prints 11
  cout << endl;
  getchar();
  return 0;
}
