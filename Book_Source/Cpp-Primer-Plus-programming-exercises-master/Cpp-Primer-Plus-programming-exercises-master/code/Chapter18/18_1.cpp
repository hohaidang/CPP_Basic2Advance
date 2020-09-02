// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<list>
#include<algorithm>
#include<initializer_list>

using namespace std;

template<class T>
T average_list(const initializer_list<T>& ls) {
	T ans{};
	for (T x : ls) ans = ans + x;
	ans = ans / (ls.end() - ls.begin());
	return ans;
}

int main() {
	auto q = average_list({ 15.4,10.7,9.0 });
	cout << q << endl;
	cout << average_list({ 20,30,19,17,45,38 }) << endl;
	auto ad = average_list<double>({ 'A',70,65.33 });
	cout << ad << endl;
	return 0;
}
