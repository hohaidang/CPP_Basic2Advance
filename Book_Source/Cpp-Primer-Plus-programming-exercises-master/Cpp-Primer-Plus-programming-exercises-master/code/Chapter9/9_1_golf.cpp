// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>
#include"9_1_golf.h"

using namespace std;

int setgolf(golf& g)
{
    cout << "Enter the name: ";
    if(cin.getline(g.fullname,Len) && g.fullname[0] != '\0'){
        cout << "Enter the handicap: ";
        cin >> g.handicap;
        cin.get();
        return 1;
    }
    return 0;
}

void setgolf(golf& g, const char* name, int hc)
{
    strcpy(g.fullname,name);
    g.handicap = hc;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}
