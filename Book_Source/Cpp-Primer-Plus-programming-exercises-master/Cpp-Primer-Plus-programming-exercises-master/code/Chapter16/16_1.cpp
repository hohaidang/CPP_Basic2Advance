// By luckycallor
// Welcome to my site: www.luckycallor.com

 #include<iostream>
 #include<string>

 using namespace std;

 bool isPa(const string& str)
 {
     auto i = str.begin();
     auto j = str.rbegin();
     for(;i != str.end() && j != str.rend();++i,++j){
        if(*i != *j) return false;
     }
     return true;
 }

 int main()
 {
     string str;
     cout << "Enter a string(null string to quit): ";
     while(getline(cin,str) && str != ""){
        if(isPa(str)) cout << "Yes!" << endl;
        else cout << "No!" << endl;
        cout << "Enter next string: ";
     }
     return 0;
 }
