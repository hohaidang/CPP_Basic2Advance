// By luckycallor
// Welcome to my site: www.luckycallor.com

namespace SALES {
	const int QUARTERS = 4;
	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales& s, const double ar[], int n = 4);

	void setSales(Sales& s);

	void showSales(const Sales& s);
}
