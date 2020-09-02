// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

const int strsize = 100;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

bop bop_arr[5] = {
                    {"Wimp Macho","Junior Programmer","WM",0},
                    {"Raki Rhodes","Junior Programmer","RR",1},
                    {"Celia Laiter","Senior Programmer","MIPS",2},
                    {"Hoppy Hipman","Analyst Trainee","HH",1},
                    {"Pat Hand","Junior Programmer","LOOPY",2}
                 };

int main()
{
    char ch;
    int flag = 0;
    cout << "Please enter one of the following choices:" << endl;
    cout << "a. display by name        " << "b. display by title" << endl;
    cout << "c. display by bopname     " << "d. display by preference" << endl;
    cout << "q. quit" << endl;
    cout << "Enter your choice: ";
    while(cin.get(ch)){
        switch(ch)
        {
            case 'a':
                {
                    for(int i=0;i<5;++i) cout << bop_arr[i].fullname << endl;
                    break;
                }
            case 'b':
                {
                    for(int i=0;i<5;++i) cout << bop_arr[i].title << endl;
                    break;
                }
            case 'c':
                {
                    for(int i=0;i<5;++i) cout << bop_arr[i].bopname << endl;
                    break;
                }
            case 'd':
                {
                    for(int i=0;i<5;++i){
                        int f = bop_arr[i].preference;
                        if(f == 0) cout << bop_arr[i].fullname << endl;
                        else if(f == 1) cout << bop_arr[i].title << endl;
                        else cout << bop_arr[i].bopname << endl;
                    }
                    break;
                }
            case 'q':
                {
                    flag = 1;
                    break;
                }
            default: break;
        }
        if(flag) break;
        while(ch != '\n') cin.get(ch);
        cout << "Next choice: ";
    }

    return 0;
}
