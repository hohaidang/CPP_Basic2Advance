#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		auto len_needle = needle.size();
		for (int i = 0; i < haystack.size(); ++i)
		{
			if (haystack.substr(i, len_needle).compare(needle) == 0) {
				return i;
			}
		}
		return -1;
	}
};


int main()
{
	Solution sol = Solution();
	auto pos = sol.strStr("hello", "ll");
	return 0;
}