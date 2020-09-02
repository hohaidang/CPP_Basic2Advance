//#include <iostream>
//#include <utility>
//#include <vector>
//using namespace std;
//
//void may_throw();
//void no_throw() noexcept;
//auto lmay_throw = [] {};
//auto lno_throw = []() noexcept {};
//
//class T
//{
//public:
//	~T() {} // dtor prevents move ctor
//			// copy ctor is no except
//};
//
//class U
//{
//public:
//	~U() {} // dtor prevents move ctor
//			// copy ctor is noexcept(false)
//	vector<int> v;
//};
//
//class V
//{
//public:
//	vector<int> v;
//};
//
//int main()
//{
//	T t;
//	U u;
//	V v;
//	cout << boolalpha
//		 << "Is may_throw() noexcept? " << noexcept(may_throw()) << "\n"
//		 << "Is no_throw() noexcpet? " << noexcept(no_throw()) << "\n";
//	return 0;
//}


#include <iostream>
#include <array>
#include <vector>
using namespace std;

class NoExceptCopy 
{
public:
	array<int, 5> arr{ 1, 2, 3, 4, 5 };
};

class NonNoExceptCopy
{
public:
	vector<int> v{ 1, 2, 3, 4, 5 };
};

template <typename T>
T copy (T const& src) noexcept(noexcept(T(src))) 
{
	return src;
}

int main()
{
	NoExceptCopy A;
	NonNoExceptCopy B;
	cout << boolalpha << endl; // print true/false instead of 1/0
	cout << "noexcept(copy(A)): " << noexcept(copy(A)) << endl;
	cout << "noexcept(copy(B)): " << noexcept(copy(B)) << endl;
}