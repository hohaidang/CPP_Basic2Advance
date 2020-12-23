#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void showList(list<int> g) {
	for(auto it = g.begin(); it != g.end(); ++it) {
		cout << "\t" << *it;
	}
	cout << "\n";
}

int main() {
	list<int> gqlist1, gqlist2;
	for(int i = 0; i < 10; ++i) {
		gqlist1.push_back(i * 2);
		gqlist2.push_back(i * 3);
	}
	cout << "\nList 1 (gqlist1) is: " ;
	showList(gqlist1);
	cout << "\ngqlist1.front(): " << gqlist1.front();
	cout << "\ngqList1.back(): " << gqlist1.back();
	gqlist1.reverse();
	cout << "\nList1 after reverse: ";
	
	showList(gqlist1);
	return 0;
}