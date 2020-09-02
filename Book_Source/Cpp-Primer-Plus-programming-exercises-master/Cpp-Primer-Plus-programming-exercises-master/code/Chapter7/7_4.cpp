// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

long double probability(unsigned numbers,unsigned picks);

int main()
{
    double total1,total2,choice1,choice2;
    cout << "Enter the total number of first and sencond choices on the game card and\n"
         << "the number of picks allowed in each choices:\n";
    while((cin >> total1 >> total2 >> choice1 >> choice2) && choice1 <= total1 && choice2 <= total2){
        cout << "You have one chance in ";
        cout << probability(total1,choice1) * probability(total2,choice2);
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye\n";
    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for(n = numbers,p = picks;p>0;n--,p--) result = result * n/p;
    return result;
}
