// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<fstream>

using namespace std;

int main(int args,char* argv[])
{
    ofstream fout;
    ifstream fin;
    fout.open(argv[1],ios_base::ate | ios_base::app);
    if(!fout.is_open()){
        cout << "Fail to open " << argv[1];
        return 1;
    }
    fin.open(argv[2],ios_base::in);
    if(!fin.is_open()){
        cout << "Fail to open " << argv[2];
        return 2;
    }
    char c;
    while(fin.get(c))fout.put(c);
    fout.close();
    fin.close();

    return 0;
}
