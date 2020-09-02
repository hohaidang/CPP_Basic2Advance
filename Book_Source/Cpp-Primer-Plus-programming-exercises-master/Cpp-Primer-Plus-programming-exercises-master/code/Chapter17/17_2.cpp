// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<fstream>

using namespace std;

int main(int argc,char* argv[])
{
    ofstream fout(argv[1]);
    char c;
    while(cin.get(c)) fout.put(c);
    fout.close();
    return 0;
}
