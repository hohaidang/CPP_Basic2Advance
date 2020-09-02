// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

struct stringy
{
    char * str;
    int ct;
};

void set(stringy& sy,char* cstr)
{
    int cnt = 0;
    while(cstr[cnt++] != '\0') continue;
    sy.str = new char[cnt];
    memcpy(sy.str,cstr,cnt);
    sy.ct = cnt-1;
}

void show(const stringy& sy,int n = 1)
{
    for(int i=0;i<n;++i) cout << sy.str << endl;
}

void show(const char* str,int n = 1)
{
    for(int i=0;i<n;++i) cout << str << endl;
}

int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing,3);
    show("Done!");
    return 0;
}
