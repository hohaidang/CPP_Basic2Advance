// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

void Ustr(string& str)
{
    int n = str.length();
    for(int i=0;i<n;++i) str[i] = toupper(str[i]);
}

int main()
{
    string str;
    cout << "Enter a string (q to quit): ";
    getline(cin,str);
    while(str.length() > 1 || str[0] != 'q'){
        Ustr(str);
        cout << str << endl;
        cout << "Next string (q to quit): ";
        getline(cin,str);
    }

    return 0;
}
