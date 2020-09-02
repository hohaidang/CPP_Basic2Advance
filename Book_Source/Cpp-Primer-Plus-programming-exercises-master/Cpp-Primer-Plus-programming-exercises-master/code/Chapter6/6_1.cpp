// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cctype>
#include<string>

using namespace std;
string buff;

int main()
{
    char c;
    while(cin.get(c)){
        if(c == '@') break;
        else if(!isdigit(c)) buff += tolower(c);
    }
    cout << buff << endl;

    return 0;
}
