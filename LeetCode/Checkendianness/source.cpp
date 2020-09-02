#include <iostream>
using namespace std;

void checkEndience() {
	uint32_t input = 0xAABBCCDD;
	uint8_t *ptr = (uint8_t *)&input;
	if(*ptr = 0xDD) {
		cout << "Little Endience" << endl;
	}
	else {
		cout << "Big Endience" << endl;
	}
}

int main() {
	checkEndience();
	return 0;
}