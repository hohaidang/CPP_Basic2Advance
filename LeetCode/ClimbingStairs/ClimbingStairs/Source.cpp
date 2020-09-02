#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		n = 35;
		vector<int> memo(n + 1, INT_MIN);
		// return recurClimb(n);
		return recurMemoClimb(n, memo);
	}

	int recurClimb(int n) {
		int result = 0;
		if (n == 1 || n == 0) {
			result = 1;
		}
		else {
			result = recurClimb(n - 1) + recurClimb(n - 2);
		}
		return result;
	}

	int recurMemoClimb(int n, vector<int> &memo) {
		int result = 0;
		if (memo[n] != INT_MIN) {
			result = memo[n];
		}
		else if (n == 1 || n == 0) {
			result = 1;
		}
		else {
			result = recurMemoClimb(n - 1, memo) + recurMemoClimb(n - 2, memo);
		}
		memo[n] = result;
		return result;
	}
};

int main()
{
	Solution sol = Solution();
	cout << sol.climbStairs(5);
	return 0;
}