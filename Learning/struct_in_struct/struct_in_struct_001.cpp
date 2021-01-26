// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>


template <int age>
struct father {
	int dang = 5;

	template<typename T>
	struct son {
		bool restricted;
	};

	struct son<int> my_son;
};

template <int year>
struct family {
	struct father<year> fat;
};

struct son2 {
	bool restricted;
};

int main() {
	father<5> my_father;
	my_father.dang = 15;
    // day la cach called 1 struct nam trong struct khac
	father<5>::son<int> my_son; // bien nay se co kieu du lieu la father<5>::son<int> chu khong phai la son
	my_son.restricted = false;
	std::cout << "size of fater::son = " << sizeof(my_son) << '\n';
	son2 dang_son; // bien nay se co kieu du lieu la son2
	dang_son.restricted = true;
	std::cout << "size of son2 = " << sizeof(dang_son) << '\n';
	family<5> my_family;
	my_family.fat.my_son.restricted = false;
    std::cout << "size of my_family = " << sizeof(my_family.fat.my_son) << '\n';
    std::cout << "offset of = " << offsetof(struct father<5>, my_son);

	return 0;
}

