#include <iostream>

//enum class egg {Small, Medium, Large};
//enum class t_shirt{Small, Medium, Large};

int main()
{
	using namespace std;
	enum egg_old { Small, Medium, Large, Jumbo }; // unscoped
	enum class t_shirt { Small, Medium, Large, Xlarge }; // scoped
	egg_old one = Medium; // unscoped
	t_shirt rolf = t_shirt::Large; // scoped
	int king = one; // implicit type conversion for unscoped
	cout << king << endl;
	//int ring = rolf; // not allowed, no implicit type conversion
	int ring_cast = int(rolf);
	cout << "size: " << sizeof(rolf) << endl;
	if (king < Jumbo) // allowed
		cout << "Jumbo converted to int before comparison.\n";
	//if (king < t_shirt::Medium) // not allowed
		//std::cout << "Not allowed: < not defined for scoped enum.\n";
}