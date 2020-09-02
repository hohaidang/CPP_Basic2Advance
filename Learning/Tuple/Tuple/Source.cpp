#include <iostream>
#include <tuple>
#include <string>

using namespace std;

tuple<bool, string> addString(const string &input)
{
	string output = input + "Dep trai vcl";
	bool retStatus = true;
	return make_tuple(retStatus, output);
}

int main()
{
	tuple <char, int, float> geek;
	geek = make_tuple('a', 10, 15.5);

	cout << "The initial values of tuple are: ";
	cout << get<0>(geek) << " " << get<1>(geek);
	cout << " " << get<2>(geek) << endl;

	string data = "Dang";
	string dataOut;
	bool status;
	//auto[status, dataOut] = addString(data); C++17
	tie(status, dataOut) = addString(data);
	cout << dataOut << endl;

	system("pause");
	return 0;
}