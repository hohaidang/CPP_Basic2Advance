#pragma once
#include <memory> //PImpl
#include <string>
using namespace std;

class User
{
public:
	~User();
	User(string name);

	// Assignment Operator and Copy Constructor
	User(const User& other);
	User& operator=(User rhs);

	// Getter
	int getSalary();

	// Setter
	void setSalary(int);

private:
	// Internal implementation class
	class Impl;

	// pointer to the internal implementation
	unique_ptr<Impl> pimpl;
};