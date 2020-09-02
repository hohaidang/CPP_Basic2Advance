#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, char> HashTbl = { {'{', '}'}, {'[' , ']'}, {'(', ')'} };

class Solution {
public:
	bool isValid(string s) {
		stack<char> stk;
		for(int i = 0; i < s.size(); ++i) {
			auto pos = HashTbl.find(s[i]);
			if(pos != HashTbl.end())
				stk.push(pos->second);
			else {
				if(!stk.empty())
				{
					char temp = stk.top();
					stk.pop();
					if(temp != s[i])
						return false;
				}
				else 
					return false;
			}
		}
		return stk.empty();
	}
};

int main(int argc, char *argv[]) {
	string s = "}";
	Solution sol = Solution();
	cout << "Result = " << sol.isValid(s) << endl;
	return 0;
}