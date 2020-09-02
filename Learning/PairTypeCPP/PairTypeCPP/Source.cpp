#include <iostream>
using namespace std;

int main()
{
	pair <string, int> PAIRData[5];
	(PAIRData + 0)->first = "Dang";
	(PAIRData + 0)->second = 25;
	(PAIRData + 1)->first = "Duc";
	(PAIRData + 1)->second = 31;

	pair<int, int> Data[4] = { make_pair(1, 2), make_pair(3, 4) };
	return 0;
}