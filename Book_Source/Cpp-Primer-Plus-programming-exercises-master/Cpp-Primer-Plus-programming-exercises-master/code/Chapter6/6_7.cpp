// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main()
{
    int vowels = 0,consonants = 0,others = 0;
    string word;
    while(cin >> word){
        char ch = word[0];
        if(isalpha(ch)){
            if(ch == 'a' || ch == 'o' || ch == 'e' || ch == 'i' || ch == 'u') vowels++;
            else if(ch == 'q' && word.size() == 1) break;
            else consonants++;
        }
        else others++;
    }
    cout << vowels << " wors beginning with vowels." << endl;
    cout << consonants << " words beginning with consonants." << endl;
    cout << others << " others." << endl;

    return 0;
}
