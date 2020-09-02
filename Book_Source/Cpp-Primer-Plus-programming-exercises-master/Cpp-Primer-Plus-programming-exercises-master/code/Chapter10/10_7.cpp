// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

class Plorg
{
private:
    string name;
    int CI;
public:
    Plorg(const string& str = "Plorga",int x = 50);
    void resetCI(int x);
    void show() const;
};

Plorg::Plorg(const string& str, int x)
{
    name = str;
    CI = x;
}

void Plorg::resetCI(int x)
{
    CI = x;
}

void Plorg::show() const
{
    cout << "Name: " << name << endl;
    cout << "CI: " << CI << endl;
}

int main()
{
    cout << "Create a default plorg." << endl;
    Plorg plorg;
    cout << "Show plorg:" << endl;
    plorg.show();
    cout << "Reset plorg's CI to 67." << endl;
    plorg.resetCI(67);
    cout << "Show plorg: " << endl;
    plorg.show();

    return 0;
}
