#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int a = 0;
		for (int i : nums) {
			a ^= i;
		}
		return a;
	}
};

int main() {
	vector<int> arr = { 1, 1, 2, 3, 4, 3, 4 };
	Solution sol = Solution();
	int a = 3;
	a ^= 10;
	a ^= 3;
	cout << sol.singleNumber(arr) << endl;
	return 0;
}