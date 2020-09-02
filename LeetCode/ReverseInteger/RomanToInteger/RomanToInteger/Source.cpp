#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
using HTbl = unordered_map<char, int>;
HTbl table = {	{'I', 1},
				{'V', 5},
				{'X', 10},
				{'L', 50},
				{'C', 100},
				{'D', 500},
				{'M', 1000}
			 };


class Solution {
public:
	int romanToInt(string s) {
		int num = 0;
		int temp = table.find('M')->second;

		for(string::size_type i = 0; i < s.size(); ++i)
		{
			auto find = table.find(s[i]);
			if (temp < find->second)
			{
				num -= 2 * temp;
			}
			num = num + find->second;
			temp = table.find(s[i])->second;
		}
		return num;
	}	
};

int main()
{
	Solution a = Solution();
	cout << a.romanToInt("LVIII");
}