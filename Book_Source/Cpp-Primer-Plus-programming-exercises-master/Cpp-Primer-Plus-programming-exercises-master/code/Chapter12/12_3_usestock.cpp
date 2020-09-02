// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include"12_3_stock.h"

const int STKS = 4;

using namespace std;

int main()
{
    Stock stocks[STKS] = {
        Stock("NanoSmart",12,20.0),
        Stock("Boffo Objects",200,2.0),
        Stock("Monolithic Obelisks",130,3.25),
        Stock("Fleep Enterprises",60,6.5)
    };

    cout << "Stock holdings:\n";
    int st;
    for(st = 0;st < STKS ; ++st) cout << stocks[st];
    const Stock *top = &stocks[0];
    for(st = 1;st < STKS;++st) top = &top->topval(stocks[st]);
    cout << "\nMost valuable holding:\n";
    cout << *top;
    return 0;
}
