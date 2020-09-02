// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"17_6_emp.h"
#include<iostream>
#include<fstream>

using namespace std;

const int SIZE = 10;

int main()
{
    abstr_emp* pc[SIZE];
    ifstream fin;
    ofstream fout;
    int cnt = 0;
    int classtype;
    fin.open("17_6_data.txt",ios_base::in);
    if(fin.is_open()){
        while(fin >> classtype){
            while(fin.get() != '\n')continue;
            switch(classtype)
            {
            case Employee:
                pc[cnt] = new employee;
                pc[cnt]->GetAll(fin);
                ++cnt;
                break;
            case Manager:
                pc[cnt] = new manager;
                pc[cnt]->GetAll(fin);
                ++cnt;
                break;
            case Fink:
                pc[cnt] = new fink;
                pc[cnt]->GetAll(fin);
                ++cnt;
                break;
            case Highfink:
                pc[cnt] = new fink;
                pc[cnt]->GetAll(fin);
                ++cnt;
                break;
            }
            pc[cnt-1]->ShowAll();
            cout << endl;
        }
        fin.close();
    }
    int cur = cnt;
    cout << endl;
    cout << "Add a employee:\n"
         << "0: employee    1: manager  2: fink\n"
         << "3: highfink    4: quit\n";
    bool flag = true;
    while(flag && (cin >> classtype)){
            while(cin.get()!= '\n')continue;
            switch(classtype)
            {
            case Employee:
                pc[cnt] = new employee;
                pc[cnt]->SetAll();
                ++cnt;
                break;
            case Manager:
                pc[cnt] = new manager;
                pc[cnt]->SetAll();
                ++cnt;
                break;
            case Fink:
                pc[cnt] = new fink;
                pc[cnt]->SetAll();
                ++cnt;
                break;
            case Highfink:
                pc[cnt] = new fink;
                pc[cnt]->SetAll();
                ++cnt;
                break;
            default:
                flag = false;
                break;
            }
            if(flag) cout << "Add a employee:\n"
                          << "0: employee    1: manager  2: fink\n"
                          << "3: highfink    4: quit\n";
    }
    fout.open("17_6_data.txt",ios_base::ate | ios_base::app);
    for(int i=cur;i<cnt;++i){
        pc[i]->WriteAll(fout);
        pc[i]->ShowAll();
        cout << endl;
    }

    fout.close();

    cout << "Done.\n";

    return 0;
}
