#include <iostream>

using namespace std;

template<typename N, typename D>
class Ratio
{
private:
	N num_;
	D demon_;
public:
	Ratio() : num_(), demon_() {} // constructor with no initial value
	Ratio(const N& num, const D& denom) : num_(num), demon_(denom) {}
	explicit operator double() const
	{
		return double(num_) / double(demon_);
	}
};

int temp()
{
	Ratio<int, double> r(5, 0.1);
	//cout << "r = " << r(;
	return 0;
}