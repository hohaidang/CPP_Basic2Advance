// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>

using namespace std;

vector<string> mat;
vector<string> pat;
vector<string> both;

int main()
{
    string temp;
    cout << "Enter Mat's friends(blank string to quit): ";
    getline(cin,temp);
    while(temp != ""){
        mat.push_back(temp);
        cout << "Enter Mat's friends(blank string to quit): ";
        getline(cin,temp);
    }
    sort(mat.begin(),mat.end());
    cout << "Mat's friends:\n";
    for(string s: mat) cout << "    " << s << endl;
    cout << endl;
    cout << "Enter Pat's friends(blank string to quit): ";
    getline(cin,temp);
    while(temp != ""){
        pat.push_back(temp);
        cout << "Enter Pat's friends(blank string to quit): ";
        getline(cin,temp);
    }
    sort(pat.begin(),pat.end());
    cout << "Pat's friends:\n";
    for(string s: pat) cout << "    " << s << endl;
    cout << endl;
    copy(mat.begin(),mat.end(),insert_iterator<vector<string> >(both,both.begin()));
    copy(pat.begin(),pat.end(),insert_iterator<vector<string> >(both,both.end()));
    sort(both.begin(),both.end());
    auto uniend = unique(both.begin(),both.end());
    cout << "Union of their friends:\n";
    for_each(both.begin(),uniend,[](string s){cout << " " << s << endl;});

    return 0;
}
