#include <iostream>
using namespace std;

int main() {
	uint8_t x = 1;
	uint32_t num = 0x0000000A;
	// Togle bit x
	num = num ^ (1 << x);
	
	// Setting bit x
	num = num | (1 << x);
	
	// Clear bit x
	num = num & ~(1 << x);
	
	// Checking a bit
	uint32_t bit;
	bit = (num >> x) & 1U;
	return 0;
}