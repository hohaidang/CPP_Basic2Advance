// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

char buff[50];

int main()
{
    cout << "Address of buff: " << (void*)buff << endl;
    chaff* cp = new(buff) chaff[2];
    cp[0].slag = 0;
    strcpy(cp[0].dross,"first element.");
    cp[1].slag = 1;
    strcpy(cp[1].dross,"second element.");

    for(int i=0;i<2;++i){
        cout << "#" << i+1 << ":" << endl;
        cout << "Address: " << &cp[i] << endl;
        cout << "Dross: " << cp[i].dross << endl;
        cout << "Slag: " << cp[i].slag << endl;
    }

    return 0;
}
