#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() 
{
	vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
	auto print = [](int num) {cout << num << "  "; };
	for_each(data.begin(), data.end(), [=](int &nums) {
		print(nums);
	});
	return 0;
}