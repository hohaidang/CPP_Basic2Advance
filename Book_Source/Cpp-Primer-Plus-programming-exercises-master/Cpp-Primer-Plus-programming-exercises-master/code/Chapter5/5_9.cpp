// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int cnt = 0;
    string word;
    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> word;
    while(word != "done"){
        ++cnt;
        cin >> word;
    }
    cout << "You entered a total of " << cnt << " words." << endl;

    return 0;
}
