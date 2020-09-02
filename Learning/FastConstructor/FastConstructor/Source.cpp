#include <iostream>
using namespace std;
#define EfficientConstructor
//#define ConventionalConstructor

class MyClass
{
private:
	int s;
	double t;
	//void init();
public:
#ifdef ConventionalConstructor
	MyClass() : s(12), t(4.5) {}; // Instantiate constructor.
#else EfficientConstructor
	MyClass(int i, double t1) : s(i), t(t1) {};
#endif
	void show()
	{
		cout << "s = " << s << endl;
		cout << "t = " << t << endl;
	}
};
int main()
{
	MyClass k(1, 2);
	k.show();
	return 0;
}