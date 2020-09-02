// By luckycallor
// Welcome to my site: www.luckycallor.com

#ifndef STOCK_H
#define STOCK_H
#include<iostream>

using namespace std;

class Stock
{
private:
    char* company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){total_val = shares * share_val;}
public:
    Stock();
    Stock(const char* co,long n = 0,double pr = 0.0);
    ~Stock();
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    const Stock& topval(const Stock& s)const;

    friend ostream& operator<<(ostream& os,const Stock& s);
};
#endif // STOCK_H
