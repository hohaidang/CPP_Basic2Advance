#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		// Checked Solution
		int min_len = INT_MAX;
		int left = 0, sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
			cout << "left = " << left << endl;
			while (sum >= s) {
				min_len = min(min_len, i - left + 1);
				sum -= nums[left++];
			}
		}
		return (min_len != INT_MAX) ? min_len : 0;
	}
};

int main() {
	int s = 7;
	vector<int>nums = { 2, 3, 1, 2, 4, 3 };
	Solution sol = Solution();
	cout << sol.minSubArrayLen(s, nums) << endl;
	return 0;
}