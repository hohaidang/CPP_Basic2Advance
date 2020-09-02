// ReferenceToArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
using namespace std;

template<typename T, size_t N>
constexpr size_t arraySize(T(&)[N]) noexcept
{
	return N;
}

int main()
{
	int a[] = { 1, 2, 3 };
	int *ap = a; // a pointer, size is lost
	int(&ar)[3] = a; //a reference array, size is not lost
    
	size_t size_of_a = arraySize(a);
	int mappArr[arraySize(a)];

	auto x = { 11, 23, 9 }; // type will be initialize_list
}

