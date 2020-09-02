// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    double d = 100,c = 100;
    int y = 0;
    while(c <= d){
        y++;
        d += 10;
        c += c*0.05;
    }

    cout << "In " << y << " years,Cleo's money is more than that of Daphne,"<< endl;
    cout << "when Cleo has " << c << " and Daphne has " << d << endl;
    return 0;
}
