// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

double add(double x,double y);
double another(double x,double y);
double calculat(double (*fuc)(double x,double y),double x,double y);

int main()
{
    double x,y;
    cout << "Enter two numbers: ";
    while(cin >> x >> y){
        cout << x << " + " << y  << " = " << calculat(add,x,y) << endl;
        cout << x << " - " << y  << " = " << calculat(another,x,y) << endl;
        cin.get();
        cout << "Enter two numbers: ";
    }
}

double add(double x, double y)
{
    return x+y;
}

double another(double x, double y)
{
    return x-y;
}

double calculat(double (* fuc)(double x, double y), double x, double y)
{
    return fuc(x,y);
}
