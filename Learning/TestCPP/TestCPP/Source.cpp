#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> num;
	num.push(10);
	num.push(20);
	num.front() = num.front() + 1;
	cout << "num1 = " << num.front() << endl;
	num.pop();
	cout << "num2 = " << num.front() << endl;
	num.pop();
	cout << "num2 = " << num.front() << endl;
	return 0;
}