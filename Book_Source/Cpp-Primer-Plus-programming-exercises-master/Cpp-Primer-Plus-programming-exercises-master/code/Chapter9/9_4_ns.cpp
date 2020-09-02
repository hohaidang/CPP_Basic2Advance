// By luckycallor
// Welcome to my site: www.luckycallor.com

#include "stdafx.h"
#include<iostream>
#include"9_4_ns.h"

namespace SALES {
	using std::cin;
	using std::cout;
	using std::endl;

	void setSales(Sales& s, const double ar[], int n) {
		s.min = ar[0];
		s.max = ar[0];
		s.average = 0;
		if (n > 4) n = 4;
		for (int i = 0; i<n; ++i) {
			s.sales[i] = ar[i];
			s.min = ar[i] < s.min ? ar[i] : s.min;
			s.max = ar[i] > s.max ? ar[i] : s.max;
			s.average += ar[i];
		}
		for (int i = n; i<4; ++i) {
			s.sales[i] = 0;
			s.min = s.sales[i] < s.min ? s.sales[i] : s.min;
			s.max = s.sales[i] > s.max ? s.sales[i] : s.max;
		}
		s.average = s.average / 4.0;
	}

	void setSales(Sales& s) {
		//double buf[4];
		int cnt = 0;
		s.average = 0;
		cout << "Enter the first sale: ";
		while (cnt < 4 && cin >> s.sales[cnt]) {
			cnt++;
			if (cnt >= 4) break;
			cout << "Enter next sale(q to quit): ";
		}
		for (int i = cnt; i<4; ++i) s.sales[i] = 0;
		s.max = s.sales[0];
		s.min = s.sales[0];
		for (int i = 0; i<4; ++i) {
			s.min = s.sales[i] < s.min ? s.sales[i] : s.min;
			s.max = s.sales[i] > s.max ? s.sales[i] : s.max;
			s.average += s.sales[i];
		}
		s.average = s.average / 4.0;
		cin.clear();
	}

	void showSales(const Sales& s) {
		cout << "The four sales: ";
		for (int i = 0; i<4; ++i) cout << s.sales[i] << " ";
		cout << endl;
		cout << "Average: " << s.average << endl;
		cout << "Max: " << s.max << endl;
		cout << "Min: " << s.min << endl;
	}
}
