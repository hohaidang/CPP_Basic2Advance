// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

class Golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf(const char* name = "",int hc = 0);
    bool setgolf();
    void Handicap(int hc);
    void show() const;
};

Golf::Golf(const char* name, int hc)
{
    strcpy(fullname,name);
    handicap = hc;
}

bool Golf::setgolf()
{
    char name[Len];
    int hc;
    cout << "Enter name: ";
    cin.getline(name,Len);
    if(name[0] == '\0') return false;
    cout << "Enter handicap: ";
    cin >> hc;
    cin.get();
    *this = Golf(name,hc);
    return true;
}

void Golf::Handicap(int hc)
{
    handicap = hc;
}

void Golf::show()const
{
    cout << "Name: " << fullname << endl;
    cout << "Handicap: " << handicap << endl;
}

int main()
{
    Golf golf[10];
    int cnt = 0;
    while(cnt < 10 && golf[cnt].setgolf()) cnt++;
    for(int i=0;i<cnt;++i) golf[i].show();
    Golf Agolf("Jack Ma",100);
    cout << "Show Agolf" << endl;
    Agolf.show();
    cout << "Modify handicap of Agolf." << endl;
    Agolf.Handicap(55);
    Agolf.show();

    return 0;
}
