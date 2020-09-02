/*
 * stock00.h
 *
 *  Created on: Feb 3, 2020
 *      Author: prnsoft
 */
#include <iostream>
#ifndef STOCK00_H_
#define STOCK00_H_

class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot()
	{
		total_val = shares * share_val;
	}

public:
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	/*This is call const Member Functions*/
	void show() const; // make sure show function() doesnot change value of object inside class
	Stock(const std::string & co, long n = 0, double pr = 0.0);
	~Stock();
	Stock();
	double total() const {return total_val;}
	const Stock & topval(const Stock & s) const;
};



#endif /* STOCK00_H_ */
