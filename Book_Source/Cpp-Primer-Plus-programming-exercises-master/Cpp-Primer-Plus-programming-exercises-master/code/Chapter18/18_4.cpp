// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

auto outint = [](int n) {cout << n << " "; };

int main() {
	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
	yadayada.remove_if([](int x) {return x > 100; });
	etcetera.remove_if([](int x) {return x > 200; });
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	return 0;
}
