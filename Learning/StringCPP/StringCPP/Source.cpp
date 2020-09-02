#include <iostream>
#include <string>
using namespace std;

int temp3()
{
	string snake1("cobra");
	string snake2("coral");
	char snake3[20] = "anaconda";
	if (snake1 < snake2)
		cout << "snake1 < snake2\n";
	else if (snake1 == snake2)
		cout << "snake1 == snake2\n";
	else
		cout << "snake1 > snake2\n";
	if (snake1.length() == snake2.size())
		cout << "both string has a same length\n";
	int where = snake1.find_first_of("hark");
	cout << "where = " << where << endl;
	return 0;
}