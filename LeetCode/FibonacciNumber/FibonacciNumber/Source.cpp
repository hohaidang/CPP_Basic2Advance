#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int fib(int N) {
		vector<int> memo;
		memo.resize(N + 1);
		return bottomUpFib(N);
		return memoFib(N, memo);
		return recursionFib(N);

	}
	// Time complexity = O(2^n) space complexity = O(1)
	int recursionFib(int N) {
		if (N == 1 || N == 2) {
			return 1;
		}
		else {
			return recursionFib(N - 1) + recursionFib(N - 2);
		}
	}

	// Time complexity = O(n) space complexity = O(n)
	int memoFib(int N, vector<int> &memo) {
		int result = 0;
		if (memo[N] != NULL)
			return memo[N];
		if (N == 1 || N == 2) {
			result = 1;
		}
		else {
			result = memoFib(N - 1, memo) + memoFib(N - 2, memo);
		}
		memo[N] = result;
		return result;
	}

	// Time complexity = O(n), space complexity = 0(1)
	int bottomUpFib(int N) {
		if (N == 1 || N == 2)
			return 1;
		int temp1 = 1;
		int temp2 = 1;
		int result = 0;
		for (int i = 3; i <= N; ++i) {
			result = temp1 + temp2;
			temp1 = temp2;
			temp2 = result;
		}
		return result;
	}
};
