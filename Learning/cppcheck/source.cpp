#include <iostream>

void foo(int x) {
	int buf[10];
	if(x == 1000)
		buf[x] = 0;
}

int main() {
	foo(100);
	return 0;
}
