//============================================================================
// Name        : TemplateInCPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

//template <typename T>
//T myMax(T x, T y)
//{
//	return (x > y) ? x : y;
//}
///* Compiler internally generate
// * int myMax(int x, int y)
// * {
// * 		return (x > y) ? x: y;
// * }*/
//
//
//int main()
//{
//	cout << "Hello World" << endl;
//	cout << myMax<int>(3, 7) << endl;
//	cout << myMax<char>('g', 'e') << endl;
//	return 0;
//}


//template <typename T>
//void bubbleSort(T a[], int n) {
//    for (int i = 0; i < n - 1; i++)
//        for (int j = n - 1; i < j; j--)
//            if (a[j] < a[j - 1])
//              swap(a[j], a[j - 1]);
//}
//
//// Driver Code
//int main() {
//    double a[5] = {2.5, 1.5, 10, 5, 3.3};
//    int n = sizeof(a) / sizeof(a[0]);
//
//    // calls template function
//    bubbleSort(a, 5);
//
//    cout << " Sorted array : ";
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//
//  return 0;
//}




template <typename T>
class Array
{
private:
	T *ptr;
	int size;
public:
	Array(T arr[], int s);
	void print();
};

template <typename T>
Array<T>::Array(T arr[], int s)
{
	ptr = new T[s];
	size = s;
	for(int i = 0; i < size; i++)
		ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print()
{
	for(int i = 0; i < size; ++i)
		cout << " " << *(ptr + i);
	cout << endl;
}


int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	Array<int> a(arr, 5);
	a.print();
	return 0;
}
