// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    string file1,file2,file3;
    ifstream fin1;
    ifstream fin2;
    ofstream fout;
    cout << "Enter the first input file:\n";
    getline(cin,file1);
    cout << "Enter the second input file:\n";
    getline(cin,file2);
    cout << "Enter the output file:\n";
    getline(cin,file3);
    fin1.open(file1.c_str());
    if(!fin1.is_open()){
        cout << "Fail to open " << file1;
        return 1;
    }
    fin2.open(file2.c_str());
    if(!fin2.is_open()){
        cout << "Fail to open " << file2;
        return 2;
    }
    fout.open(file3.c_str());
    if(!fout.is_open()){
        cout << "Fail to open " << file3;
        return 3;
    }
    string temp1,temp2;
    while(getline(fin1,temp1)){
        fout << temp1;
        if(getline(fin2,temp2)) fout << " " << temp2;
        fout << endl;
    }
    while(getline(fin2,temp2)) fout << temp2 << endl;

    fin1.close();
    fin2.close();
    fout.close();

    cout << "Done!\n";

    return 0;
}
