#include <iostream>
template<typename T>   // primary template
struct is_void : std::false_type
{
};
template<>  // explicit specialization for T = void
struct is_void<void> : std::true_type
{
};

template <typename T>
T do_something(T x) { return ++x; }

/*If input of do_something is <double>, this do_something will be called*/
template <>
double do_something<double>(double x) { return x / 2; }


int temp3()
{
	
	auto a = do_something(3);    // a = 4, do_something with any type
	a = do_something(3.0);  // a = 1.5, do_something with double

	// for any type T other than void, the 
	// class is derived from false_type
	std::cout << is_void<char>::value << '\n';
	// but when T is void, the class is derived
	// from true_type
	std::cout << is_void<void>::value << '\n';
	return 0;
}


