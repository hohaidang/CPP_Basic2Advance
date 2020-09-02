#include <iostream>
using namespace std;

class Test {
	
public:
	int a;
	mutable int b;
	constexpr Test(int x = 0, int y = 0) noexcept
		: a{ x }, b{y} 
	{}
	
	void display() const
	{
		cout << "a = " << a;
	}
};
int main() {
	constexpr Test t(10, 20);
	cout << t.a << " " << t.b << "\n";
	// t.a=30; //Error occurs because a can not be changed, because object is constant.
	t.b = 100; //b still can be changed, because b is mutable.
	cout << t.a << " " << t.b << "\n";
	t.display();
	return 0;
}