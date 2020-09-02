#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	bool isParlidorme(string s)
	{
		for_each(s.begin(), s.end(), [](char &c) {
			c = tolower(c);
		});
		int first = 0;
		int last = s.length() - 1;
		while (first < last)
		{
			if (s[first++] != s[last--]) {
				return false;
			}
		}
		return true;
	}

	bool isParlidorme1(string s)
	{
		for_each(s.begin(), s.end(), [](char &c) {
			c = tolower(c);
		});
		string reverse = "";
		for_each(s.begin(), s.end(), [&reverse](char &c) {
			reverse = c + reverse;

		});
		if (reverse == s) return true;
		else return false;
	}

	bool isParlidorme2(string s)
	{
		string temp;
		for_each(s.begin(), s.end(), [&temp](char c) {
			c = tolower(c);
			if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
			{
				temp += tolower(c);
			}
		});
		string reverse = "";
		for_each(temp.begin(), temp.end(), [&reverse](char c) {
			reverse = c + reverse;

		});
		if (reverse == temp) return true;
		else return false;
	}

	bool isParlidorme3(string s)
	{
		string reverse_str = "", filter_str;
		for_each(s.begin(), s.end(), [&filter_str](char &c) {
			if (isalnum(c))
			{
				filter_str += tolower(c);
			}
		});
		reverse_str.resize(filter_str.length());
		reverse_copy(filter_str.begin(), filter_str.end(), reverse_str.begin());
		return (reverse_str == filter_str) ? true : false;
	}
};

int main()
{
	string input("A man, a plan, a canal: Panama");
	string input1("ABBA1");
	Solution sol = Solution();

	//cout << "\n" << boolalpha <<  sol.isParlidorme2(input1) << endl;;
	cout << "\n" << boolalpha << sol.isParlidorme3(input) << endl;
	return 0;
}