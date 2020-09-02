// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

class Cd{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(char* s1,char* s2,int n,double x);
    Cd(const Cd& d);
    Cd();
    //virtual ~Cd(){};
    virtual void Report() const;
    //virtual Cd& operator=(const Cd& d);
};

class Classic: public Cd{
private:
    char works[100];
public:
    Classic(char* s1 = "",char* s2 = "",char* s3 = "",int n = 0,double x = 0.0);
    Classic(const Cd& d,char* s = "");
    void Report() const;
};

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::Cd(const Cd& d)
{
    strcpy(performers,d.performers);
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd(char* s1, char* s2, int n, double x)
{
    strcpy(performers,s1);
    strcpy(label,s2);
    selections = n;
    playtime = x;
}

void Cd::Report()const
{
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

Classic::Classic(char* s1, char* s2, char* s3, int n, double x):Cd(s2,s3,n,x)
{
    strcpy(works,s1);
}

Classic::Classic(const Cd& d,char* s): Cd(d)
{
    strcpy(works,s);
}

void Classic::Report()const
{
    Cd::Report();
    cout << "Works: " << works << endl;
}

void Bravo(const Cd& disk);

int main()
{
    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C","Alfred Brendel","Philips",2,57.17);
    Cd* pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd* pointer to objects:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd& dist)
{
    dist.Report();
}

