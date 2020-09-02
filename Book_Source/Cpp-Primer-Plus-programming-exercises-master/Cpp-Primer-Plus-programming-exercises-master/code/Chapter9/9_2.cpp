// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

void strcount(const string& str)
{
    static int total = 0;
    total += str.length();
    cout << "\"" << str << "\"" << "contains " << str.length() << " characters" << endl;
    cout << total << "charactors total" << endl;
}

int main()
{
    string str;
    //char next;

    cout << "Enter a line:\n";
    getline(cin,str);
    while(str != ""){
        //cin.get(next);
        //while(next != '\n') cin.get(next);
        strcount(str);
        cout << "Enter next line (empty line to quit):\n";
        getline(cin,str);
    }

    cout << "Bye!" << endl;
    return 0;
}
