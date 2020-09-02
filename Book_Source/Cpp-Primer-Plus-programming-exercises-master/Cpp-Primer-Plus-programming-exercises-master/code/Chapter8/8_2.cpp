// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

struct CandyBar
{
    string brand = "Millennium Munch";
    double weight = 2.85;
    int heat = 350;
};

void Fill(CandyBar& cb,const string& str,double w,int h)
{
    cb.brand = str;
    cb.weight = w;
    cb.heat = h;
}

void Show(const CandyBar& cb)
{
    cout << "Brand: " << cb.brand << endl;
    cout << "Weight: " << cb.weight << endl;
    cout << "Heat: " << cb.heat << endl;
}

int main()
{
    string str;
    double w;
    int h;
    CandyBar cb;
    cout << "The default infomation: " << endl;
    Show(cb);
    cout << "Enter the brand: ";
    getline(cin,str);
    cout << "Enter the weight: ";
    cin >> w;
    cin.get();
    cout << "Enter the heat: ";
    cin >> h;
    Fill(cb,str,w,h);
    cout << "The information you entered:" << endl;
    Show(cb);

    return 0;
}
