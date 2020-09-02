///*
// * main.cpp
// *
// *  Created on: Jan 20, 2020
// *      Author: prnsoft
// */
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	cout << "Hello World" << endl;
//	vector<int> g1;
//
//	for(int i = 1; i <= 5; ++i)
//	{
//		g1.push_back(i);
//	}
//	cout << "Output of begin and end: ";
//	for(auto i = g1.begin(); i != g1.end(); ++i)
//	{
//		cout << *i << " ";
//	}
//
//	cout << "\nOutput of cbegin and cend: ";
//	for(auto i = g1.cbegin(); i != g1.cend(); ++i)
//	{
//		cout << *i << " ";
//	}
//
//	cout << "\nOutput of rbegin and rend: ";
//	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
//	{
//		cout << *ir << " ";
//	}
//
//	cout << "\nOutput of crbegin and crend: ";
//	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
//	{
//		cout << *ir << " ";
//	}
//
//
//	return 0;
//}
//
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int a = 255;
	cout <<"Hex = " << std::hex << a << endl;
//    vector<int> g1;
//
//    cout << "sizeof int = " << sizeof(int) << endl;
//    for (int i = 1; i <= 4; i++)
//        g1.push_back(i);
//
//    cout << "Size : " << g1.size();
//    cout << "\nCapacity : " << g1.capacity();
//    cout << "\nMax_Size : " << g1.max_size();
//
//    // resizes the vector size to 4
//    g1.resize(4);
//
//    // prints the vector size after resize()
//    cout << "\nSize : " << g1.size();
//
//    // checks if the vector is empty or not
//    if (g1.empty() == false)
//        cout << "\nVector is not empty";
//    else
//        cout << "\nVector is empty";
//
//    // Shrinks the vector
//    g1.shrink_to_fit();
//    cout << "\nVector elements are: ";
//    for (auto it = g1.begin(); it != g1.end(); it++)
//        cout << *it << " ";
//
//    return 0;
}
