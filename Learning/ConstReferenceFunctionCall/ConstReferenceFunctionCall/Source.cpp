#include <iostream>
#include <vector>
using namespace std;

void constRef(const vector<char> &vec)
{
	cout << "Address of vector in constRef: " << &vec << endl;
}
void noConstRef(const vector<char> vec)
{
	// this function have to copy vec to another location, this is not efficent.
	cout << "Address of vector in noConstRef: " << &vec << endl;
}

int main()
{
	vector<char> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	cout << "Address of vector before Called: " << &vec << endl;
	cout << "Size of vector: " << sizeof(vec) << endl;
	constRef(vec);
	noConstRef(vec);
	return 0;
}