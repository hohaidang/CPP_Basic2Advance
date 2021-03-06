#include <iostream>
#include <vector>
#include <typeinfo>

template<typename Container>
auto findInPosition(Container& c, int position)->decltype(*(c.begin()))
{
	if(std::distance(c.begin(), c.begin() + position) < c.size())
		return c.at(position);
}


int main() {
	std::vector<int> arr{1, 2, 3, 4, 5};
	auto position = findInPosition(arr, 2);
	std::cout << "position = " << position << '\n';
	std::cout << "position type = " << typeid(position).name() << '\n';
	return 0;
}
