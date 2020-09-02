#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> numbers(1000);
const long Size1 = 39L;
const long Size2 = 100 * Size1;
const long Size3 = 100 * Size2;

bool f3(int x)  { return (x % 3 == 0); };
bool f13(int x) { return (x % 13 == 0); };

class f_mod 
{
private:
	int dv;
public:
	f_mod(int d = 1) : dv(d) {}
	bool operator()(int x) { return x % dv == 0; }
};

int temp2()
{
	generate(numbers.begin(), numbers.end(), rand);
	int count3 = count_if(numbers.begin(), numbers.end(), f3);
	cout << "Count of numbers divisible by 3: " << count3 << '\n';
	int count13 = count_if(numbers.begin(), numbers.end(), f13);
	cout << "Count of numbers divisible by 13: " << count13 << "\n";

	f_mod obj(3);
	bool is_div_by_3 = obj(3);
	count3 = count_if(numbers.begin(), numbers.end(), f_mod(3)); // now f_mod can replace f3 and f13

	// Now apply lambda expression
	count3 = count_if(numbers.begin(), numbers.end(), [](int x) { return (x % 3 == 0); });

	for_each(numbers.begin(), numbers.end(),
		[&](int x) {count3 += x % 3 == 0; count13 += x % 13 == 0; });
	return 0;
}