#include <iostream>
#include <string>
#include <bitset>

using namespace std;
// Input: a = "1010", b = "1011"
// Output: "10101"
class Solution {
public:
    string addBinary(string a, string b) {
		string answer = "";
		int carry = 0;
		for(int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
			int temp1 = (i >= 0 && a[i] == '1');
			int temp2 = (j >= 0 && b[j] == '1');
			answer = to_string(temp1 ^ temp2 ^ carry) + answer;
			carry = (temp1 + temp2 + carry) >> 1;
		}
		if(carry != 0) {
			answer = to_string(carry & 1) + answer;
		}
		return answer;
    }
};

int main()
{
	string a = "11";
	string b = "1";
	// string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
	// string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"; 
	Solution sol = Solution();
	cout << "Result = " << sol.addBinary(a, b);
	return 0;
}