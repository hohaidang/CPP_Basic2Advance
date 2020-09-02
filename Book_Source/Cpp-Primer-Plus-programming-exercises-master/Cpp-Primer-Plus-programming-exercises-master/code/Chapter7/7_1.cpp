// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

double Hmean(double x,double y);

int main()
{
    double x,y;
    cout << "Input two numbers: ";
    while(cin >> x >> y){
        if(x == 0 || y == 0) break;
        double hmean = Hmean(x,y);
        cout << "The Harmonic mean of the two numbers is " << hmean << endl;
        cout << "Input two numbers: ";
    }
    return 0;
}

double Hmean(int x, int y)
{
    return 2.0*x*y/(x+y);
}
