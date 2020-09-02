#include <iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		auto output = 0;
		bool flag = 0;
		if (x > INT_MAX || x <= INT_MIN) return 0;
		while (1) {
			if (x < 0) {
				flag = 1;
				x = abs(x);
			}
			int pos = x % 10;
			x = x / 10;
			long long int checkRange = (long long int)output * 10;
			if (checkRange > INT_MAX) {
				return 0;
			}
			output = checkRange + pos;
			if (x <= 0) break;
		}
		if (flag == 1) {
			return -output;
		}
		else {
			return output;
		}
	}
};

int main() {
	Solution sol = Solution();
	cout << sol.reverse(1000000005);
	cout << "\n" << sizeof(long long);
}