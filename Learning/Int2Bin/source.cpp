#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> binaryNumber;
	int array[32];
	cout << "Input number you want to convert: ";
	cin >> n;
	int i = 0;
	while(n > 0) {
		binaryNumber.insert(binaryNumber.begin(), n%2);
		n = n / 2;

	}
	
	for(int i = 0; i < binaryNumber.size(); ++i) {
		cout << binaryNumber[i];
	}

	return 0;
}