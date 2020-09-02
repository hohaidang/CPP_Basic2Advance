#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob_recur(vector<int>& nums) {
		int profit = 0;
		for (int i = 0; i < nums.size(); ++i) {
			profit = max(profit, recur(nums, i + 1));
		}
		return profit;
	}

	int recur(vector<int>& nums, int n) {
		int result = 0;
		if (n == 0 || n == -1)
			return 0;
		else {
			result = max(recur(nums, n - 2) + nums[n-1], recur(nums, n - 1));
		}
		return result;
	}

	int rob_recur_memo(vector<int> &nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		else if (len == 1) {
			return nums[0];
		}
		else if (len == 2) {
			return max(nums[1], nums[0]);
		}
		int profit = 0;
		vector<int> memo(len + 1, INT_MIN);
		memo[0] = nums[0];
		memo[1] = max(memo[0], nums[1]);
		for (int i = 2; i < len; ++i) {
			profit = max(profit, recur2(nums, memo, i));
		}
		return profit;
	}

	int recur2(vector<int> &nums, vector<int> &memo, int n) {
		int result = 0;
		if (memo[n] != INT_MIN) {
			result = memo[n];
		}
		else {
			result = max(recur2(nums, memo, n - 2) + nums[n], recur2(nums, memo, n - 1));
			memo[n] = result;
		}
		return result;
	}

	int buttomUpRob(vector<int> &nums) {
		int n_m1 = 0, n_m2 = 0;
		int profit = 0;
		for (int i = 0; i < nums.size(); ++i) {
			profit = max(n_m2 + nums[i], n_m1);
			n_m2 = n_m1;
			n_m1 = profit;
		}
		return profit;
	}
};

// [2,7,9,3,1]

// f(1) = A1
// f(2) = max(A1, A2)
// f(3) = max(f(1) + A3, f(2))
// f(4) = max(f(2) + A4, f(3))
// f(5) = maX(f(3) + A5, f(4))

// => f(n) = max(f(n-2) + An, f(n-1));

int main()
{
	Solution sol = Solution();
	vector<int> nums = { 2,7,9,3,1 };
	//cout << sol.rob_recur_memo(nums);
	cout << sol.buttomUpRob(nums);
}