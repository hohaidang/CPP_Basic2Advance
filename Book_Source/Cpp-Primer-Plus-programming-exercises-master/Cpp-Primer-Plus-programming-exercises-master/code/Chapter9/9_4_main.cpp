// By luckycallor
// Welcome to my site: www.luckycallor.com

#include "stdafx.h"


#include"9_4_ns.h"
#include<iostream>

using namespace SALES;

int main() {
	Sales s1, s2;
	setSales(s1);
	double s[4] = { 783.3,478.2,387.4,892.7 };
	setSales(s2, s, 4);
	showSales(s1);
	showSales(s2);

	return 0;
}


