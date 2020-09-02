//============================================================================
// Name        : ClassCPP.cpp
// Author      : Dang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stock00.h"



int main() {
//	{ // this brace to use to show deconstructor message after main() end
//		using std::cout;
//		cout << "Using constructors to create new objects\n";
//		Stock stock1("NanoSmart", 12, 20.0); // syntax2
//		stock1.show();
//		Stock stock2 = Stock("Boffo Object", 2, 2.0); // syntax1
//		stock2.show();
//
//		cout << "Assigning stock1 to stock2:\n";
//		stock2 = stock1;
//		cout << "Listing stock1 and stock2:\n";
//		stock1.show();
//		stock2.show();
//
//		cout << "Using a constructor to reset an object\n";
//		// always create a temporary object, then copy and remove immediately
//		stock1 = Stock("Nifty Food", 10, 50.0);
//		cout << "Revised stock1: \n";
//		stock1.show();
//		cout << "Done\n";
//	}
//
//	{
//		const Stock land = Stock("Kludgehorn Properties");
//		land.show();
//	}
	/*This Pointer*/
	const int STKS = 4;
	Stock stocks[STKS] = {
			Stock("NanoSmart", 12.5, 20),
			Stock("Boffo Object", 200, 2.0),
			Stock("Monolithic Obelisks", 130, 3.25),
			Stock("Fleep Enterprises", 60, 6.5)
	};
	const Stock tops = stocks[0].topval(stocks[3]);
	tops.show();

	std::cout << "Stock holding: \n";
	int st;
	for(st = 0; st < STKS; st++) stocks[st].show();
	const Stock *top = &stocks[0];
	for (st = 1; st < STKS; st++)
	{
		top = &top->topval(stocks[st]);
	}
	top->show();
	return 0;
}
