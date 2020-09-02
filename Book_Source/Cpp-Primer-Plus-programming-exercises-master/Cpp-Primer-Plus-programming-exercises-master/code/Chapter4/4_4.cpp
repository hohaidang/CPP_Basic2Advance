// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string fstName,lstName,fllName;

    cout << "Enter your firstname: ";
    getline(cin,fstName);
    cout << "Enter your lastname: ";
    getline(cin,lstName);

    fllName = lstName + ", " + fstName;
    cout << "Here's the information in a single string: " << fllName << endl;

    return 0;
}
