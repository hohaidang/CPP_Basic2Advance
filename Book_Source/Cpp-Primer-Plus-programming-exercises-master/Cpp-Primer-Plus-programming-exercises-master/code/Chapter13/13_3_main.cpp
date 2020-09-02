// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<cstring>
#include<iostream>
#include"13_3_dma.h"

using namespace std;

const int CLIENTS = 4;

int main()
{
    ABCDMA* p_clients[CLIENTS];
    char temp[40];
    char col[40];
    char sty[40];
    int rat;
    char kind;

    for(int i=0;i<CLIENTS;++i){
        cout << "Enter the label: ";
        cin.getline(temp,40);
        cout << "Enter the rating: ";
        cin >> rat;
        cin.get();
        cout << "Enter 1 for baseDMA or 2 for lacksDMA, or 3 for hasDMA: ";
        while(cin >> kind && kind != '1' && kind != '2' && kind != '3'){
            while(cin.get() != '\n') continue;
            cout << "Enter 1,2 or 3: ";
        }
        while(cin.get() != '\n') continue;
        if(kind == '1'){
            p_clients[i] = new baseDMA(temp,rat);
        }
        else if(kind == '2'){
            cout << "Enter the color: ";
            cin.getline(col,40);
            p_clients[i] = new lacksDMA(col,temp,rat);
        }
        else{
            cout << "Enter the style: ";
            cin.getline(sty,40);
            p_clients[i] = new hasDMA(sty,temp,rat);
        }
        //while(cin.get() != '\n') continue;
    }

    cout << endl;
    for(int i=0;i<CLIENTS;++i){
        p_clients[i]->View();
        cout << endl;
    }
    delete [] p_clients;
    cout << "Done!\n";

    return 0;
}
