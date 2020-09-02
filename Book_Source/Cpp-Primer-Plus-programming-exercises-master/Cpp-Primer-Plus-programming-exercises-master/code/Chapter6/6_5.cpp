// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    int earn;
    double tax;
    cout << "Enter your earning: ";
    while(cin >> earn){
        if(earn < 0) break;
        if(earn > 0 && earn <= 5000) tax = 0;
        else if(earn <= 15000) tax = (earn - 5000)*0.1;
        else if(earn <= 3500) tax = 1000 + (earn - 15000) * 0.15;
        else tax = 1000 + 3000 + (earn - 35000) * 0.2;
        cout << "Your tax is " << tax << " tvarps." << endl;
        cout << "Enter your earning: ";
    }

    return 0;
}
