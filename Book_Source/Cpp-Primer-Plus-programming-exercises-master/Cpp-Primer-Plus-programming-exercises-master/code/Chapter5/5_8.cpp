// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int cnt = 0;
    char word[20];
    cout << "Enter words (to stop, type the word done):" << endl;
    cin >> word;
    while(strcmp(word,"done")){
        cnt++;
        cin >> word;
    }
    cout << "You entered a total of " << cnt << " words." << endl;

    return 0;
}
