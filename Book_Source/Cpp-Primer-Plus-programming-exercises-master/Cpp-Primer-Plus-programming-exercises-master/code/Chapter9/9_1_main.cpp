// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include"9_1_golf.h"

using namespace std;

int main()
{
    golf g[10];
    golf gd;
    int cnt = 0;
    setgolf(gd,"Jack Ma",100);
    cout << "Default: " << endl;
    showgolf(gd);
    while(cnt < 10 && setgolf(g[cnt])) cnt++;
    for(int i=0;i<cnt;++i) showgolf(g[i]);

    return 1;
}
