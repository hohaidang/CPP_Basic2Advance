// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string name;
    string dessert;

    cout << "Enter your name:\n";
    getline(cin,name); // "cin >> name" will stop at blankspace,
                       //and ether "cin.getline(name,20)" or "cin.getline(name)" is illegal.
    cout << "Enter your favorite dessert:\n";
    getline(cin,dessert); // the same as getline(cin,name).
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";

    return 0;
}
