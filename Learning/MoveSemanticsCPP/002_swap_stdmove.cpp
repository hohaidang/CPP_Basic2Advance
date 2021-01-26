// std_move_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template <class T>
void swap_copy(T& a, T& b)
{
	T tmp(a);
	a = b;
	b = tmp;
}

template<class T>
void swap_move(T &a, T &b)
{
	T tmp(move(a));
	a = move(b);
	b = move(tmp);
}

class A
{
public:
	A(vector<int>&& v) : _v(move(v)) {}
private:
	vector<int> _v;
};

int main()
{
    cout << "Hello World!\n";
	int a = 5;
	int b = 10;
	swap_move(a, b);
	cout << "a = " << a << "\n" << "b = " << b << endl;
}

