#include <iostream>

using namespace std;

class bad_1 {};
class bad_2 : public bad_1 {};
class bad_3 : public bad_2 {};

bool oh_no, rats, drat;

void duper()// noexcept
{
	if (oh_no)
		throw bad_1();
	if (rats)
		throw bad_2();
	if (drat)
		throw bad_3();
}

int main()
{
	drat = 1;
	try
	{
		duper();
	}
	catch (bad_3 &be)
	{
		cout << "Bad_3 is called\n";
	}
	catch (bad_2 &be)
	{
		cout << "Bad_2 is called\n";
	}
	catch (bad_1 &be)
	{
		cout << "Bad_1 is called\n";
	}
	catch (...)
	{
		cout << "God knows why";
	}
	return 0;
}