#include <iostream>
using namespace std;

uint32_t convertEndieness(uint32_t input) {
	uint32_t answer = 0;
	answer |= (input & 0x000000FF) << 24;
	answer |= (input & 0x0000FF00) << 8;
	answer |= (input & 0x00FF0000) >> 8;
	answer |= (input & 0xFF000000) >> 24;
	return answer;
}


int main() {
	uint32_t data = 0x11223344;
	uint32_t answer = convertEndieness(data);
	cout << hex << answer << endl;
	
	return 0;
}