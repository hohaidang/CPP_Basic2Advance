#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//#define NON_TYPE_TEMPLATE
//#define INT_TEMPLATE

#ifdef INT_TEMPLATE
template <typename T, size_t N>
class Array
{
public:
	T& operator[](size_t i)
	{
		if (i >= N) throw std::out_of_range("Bad index");
		return data_[i];
	}
private:
	T data_[N];
};
#endif

#ifdef NON_TYPE_TEMPLATE
template <template <typename> class Out_container,
		  template <typename> class  In_container,
		  typename T>
Out_container<T> resequence(const In_container<T>& in_container)
{
	Out_container<T> out_container;
	for (auto x : in_container)
	{
		out_container.pushback(x);
	}
	return out_container;
}
#endif

template <typename T>
T half(T x) { return x / 2; };

template <typename U, typename V>
std::pair<V, U> swap12(const std::pair<U, V>& x) {
	return std::pair<V, U>(x.second, x.first);
}

int tempb()
{
#ifdef INT_TEMPLATE
	Array<int, 5> a;
	cout << "Add value a[0]";
	cin >> a[0];
	cout << "a[0] = " << a[0] << endl;
#endif

#ifdef NON_TYPE_TEMPLATE
	vector<int> v{ 1, 2, 3, 4, 5 };
	auto d = resequence<deque>(v);
#endif // !1

	int i = half<int>(5);
	long x = 10;
	unsigned int y = 5;
	auto z = half(x + y);
	
	auto k = make_pair(7, 4.2);
	cout << k.first << endl;


	
	swap12(std::make_pair(7, 4.2)); // pair of 4.2, 7
	return 0;
}