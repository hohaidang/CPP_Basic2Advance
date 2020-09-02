#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

unique_ptr<string> demo(const char *s)
{
	unique_ptr<string> temp(new string(s));
	return temp;
}

unique_ptr<int> make_int(int n)
{
	return unique_ptr<int>(new int(n));
}

void show(unique_ptr<int> & pi) // pass by reference
{
	cout << *pi << ' ';
}

int temp33()
{
	unique_ptr<string> ps;
	ps = demo("Uniquely special");
	unique_ptr<string> pt1;
	//pt1 = ps; // not allow, not safe with deconstructor
	pt1 = move(ps);
	cout << *pt1 << endl;
	unique_ptr<int []> data (new int[5]);

	vector<unique_ptr<int> > vp(20);
	vector<int> testdata(20);
	for (int i = 0; i < vp.size(); i++)
	{
		vp[i] = make_int(rand() % 1000);
	}
	vp.push_back(make_int(rand() % 1000));
	for (int i = 0; i < vp.size(); i++)
	{
		show(vp[i]);
	}
	return 0;
}