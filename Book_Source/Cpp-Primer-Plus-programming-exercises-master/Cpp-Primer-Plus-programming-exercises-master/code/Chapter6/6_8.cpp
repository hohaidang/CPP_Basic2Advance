// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    char ch;
    int cnt = 0;
    ifstream fin;
    fin.open("txt.txt");
    while(fin.get(ch)) cnt++;

    cout << "There are " << cnt << " chars in the file." << endl;

    return 0;
}
