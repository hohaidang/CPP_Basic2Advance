// By luckycallor
// Welcome to my site: www.luckycallor.com

#include "stdafx.h"
#include<valarray>
#include<iostream>
#include<string>

using namespace std;

template<class T>
class Pair {
private:
	T first;
	T second;
public:
	Pair() {}
	Pair(const T& item1, const T& item2) :first(item1), second(item2) {}
	T& getFirst() { return first; }
	T& getSecond() { return second; }
	void setFirst(T item) { first = item; }
	void setSecond(T item) { second = item; }
};

class Wine {
private:
	string label;
	Pair<valarray<int> > yb;
	int years;
public:
	Wine();
	Wine(const char* l, int y, const int yr[], const int bot[]) :label(l), yb(valarray<int>(yr, y), valarray<int>(bot, y)), years(y) {}
	Wine(const char* l, int y);
	void GetBottles();
	string& Label() { return label; }
	int sum() { return yb.getSecond().sum(); }
	void Show() const;
};

Wine::Wine() {
	label = "none";
	years = 0;
	yb = Pair<valarray<int> >(valarray<int>(years), valarray<int>(years));
}

Wine::Wine(const char* l, int y) {
	label = l;
	years = y;
	yb = Pair<valarray<int> >(valarray<int>(years), valarray<int>(years));
}

void Wine::GetBottles() {
	valarray<int>& temp = yb.getSecond();
	valarray<int>& tempp = yb.getFirst();
	int cnt = temp.size();
	for (int i = 0; i<cnt; ++i) {
		cout << "Enter the bottles in year " << tempp[i] << ": ";
		cin >> temp[i];
	}
}

void Wine::Show() const {
	cout << "Wine: " << label << endl;
	valarray<int>& temp = yb.getSecond();
	valarray<int>& tempp = yb.getFirst();
	int cnt = temp.size();
	cout << "Year  " << "  Bottles" << endl;
	for (int i = 0; i<cnt; ++i) cout << tempp[i] << "    " << temp[i] << endl;
}

int main() {
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;
	cout << "Bye!\n";
	return 0;
}
