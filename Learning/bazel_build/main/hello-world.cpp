#include <iostream>
#include "hello-greet.h"

int main() {
	#ifdef FLAG
		std::cout << "FLAG DEFINED\n";
	#else
		std::cout << "NO FLAG\n";
	#endif
	print_hello_greet();
	
	return 0;
}