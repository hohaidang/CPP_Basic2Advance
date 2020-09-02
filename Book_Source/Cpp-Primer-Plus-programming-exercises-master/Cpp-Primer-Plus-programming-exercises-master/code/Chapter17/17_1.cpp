// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

int main()
{
    char c;
    int cnt = 0;
    while((c = cin.peek()) != '$'){
        cin.get();
        ++cnt;
    }

    cout << "There are " << cnt << " chars before $.\n";

    return 0;
}
