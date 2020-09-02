#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];
		string dataRet = "";
		string tempData = strs[0];
		strs.erase(strs.begin());
		for (int i = 0; i < tempData.size(); ++i)
		{
			bool flag = false;
			for (const auto &str : strs)
			{
				if (tempData.substr(0, i+1).compare(str.substr(0, i+1)) == 0)
				{
					flag = true;
				}
				else
				{
					return dataRet;
				}
			}
			if (flag == true)
			{
				dataRet = tempData.substr(0, i+1);
			}
		}
		return dataRet;
	}

	string longestCommonPrefix2(vector<string>& strs)
	{
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];
		string dataRet = "";
		auto n = strs.size();
		sort(strs.begin(), strs.end());
		auto first = strs[0];
		auto last = strs[n - 1];
		auto MinLength = min(first.size(), last.size());
		auto i{ 0 };
		while (i < MinLength && first[i] == last[i])
		{
			++i;
		}
		return first.substr(0, i);
	}
};

int main()
{
	Solution a = Solution();
	vector<string> data = {"aaa","aa","aaa"};
	cout << a.longestCommonPrefix2(data);
}