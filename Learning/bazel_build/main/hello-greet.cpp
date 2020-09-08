#include <iostream>
#include "hello-greet.h"
#include "hello-lib.h"

void print_hello_greet() {
	std::cout << "Hello Greet" << '\n';
	std::cout << "Data global = " << data_glob << '\n';
}