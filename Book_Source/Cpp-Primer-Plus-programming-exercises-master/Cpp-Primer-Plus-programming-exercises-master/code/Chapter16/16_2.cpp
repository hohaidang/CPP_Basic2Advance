// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

char Tolower(const char& c)
{
    char cc = tolower(c);
    return cc;
}

bool isPa(const string& str)
{
    string strc;
    transform(str.begin(),str.end(),insert_iterator<string>(strc,strc.begin()),Tolower);
    auto i = strc.begin();
    auto j = strc.rbegin();
    while(i != strc.end() && j != strc.rend()){
        if(!isalpha(*i)){
            ++i;
            continue;
        }
        if(!isalpha(*j)){
            ++j;
            continue;
        }
        if(*i != *j) return false;
        ++i;
        ++j;
    }
    return true;
}

int main()
 {
     string str;
     cout << "Enter a string(null string to quit): ";
     while(getline(cin,str) && str != ""){
        if(isPa(str)) cout << "Yes!" << endl;
        else cout << "No!" << endl;
        cout << "Enter next string: ";
     }
     return 0;
 }
