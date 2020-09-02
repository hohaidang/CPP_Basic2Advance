#include <iostream>
using namespace std;

uint32_t convertEndian(uint32_t input) {
	uint32_t answer = 0;
	answer |= (input & 0x000000FF) << 24;
	answer |= (input & 0x0000FF00) << 8;
	answer |= (input & 0x00FF0000) >> 8;
	answer |= (input & 0xFF000000) >> 24;
	return answer;
} 

int main() {
	uint32_t num = 0x11223344;
	cout << "Before convert: " << hex << num << endl;
	cout << "After convert: " << hex << convertEndian(num) << endl;
	return 0;
}