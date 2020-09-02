#include <iostream>

using namespace std;

int main()
{
	//double prices[5] = { 4.99, 10.99, 6.85, 7.99, 8.49 };
	///*Not modify array*/
	//for (double x : prices)
	//	cout << x << endl;
	///*Modify array*/
	//cout << "-----Modyfied-----\n";
	//for (double &x : prices)
	//	x = x * 0.80;
	//for (double x : prices)
	//	cout << x << endl;
	//return 0;
	double values[5] = { 4.99, 10.99, 6.85, 7.99, 8.49 };
	auto it = std::begin(values); //std::begin is a free function in C++11
	for (auto& value : values)
	{
		//Use value or it - whatever you need!
		//...
		cout << value << endl;
		++it; //at the end OR make sure you do this in each iteration
	}
}