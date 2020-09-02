// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<cstring>

using namespace std;

class Cow
{
private:
    char name[20];
    char* hobby;
    double weight;
public:
    Cow();
    Cow(const char* nm,const char*ho,double wt);
    Cow(const Cow& c);
    ~Cow();
    Cow& operator=(const Cow& c);
    void ShowCow() const;
};

Cow::Cow(const Cow& c)
{
    strcpy(name,c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight = c.weight;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
    strcpy(name,nm);
    hobby = new char[strlen(ho)+1];
    strcpy(hobby,ho);
    weight = wt;
}

Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby[0] = '\0';
    weight = 0.0;
}

Cow::~Cow()
{
    cout << name << " deleted!\n";
    delete [] hobby;
}


Cow& Cow::operator=(const Cow& c)
{
    if(this == &c) return *this;
    strcpy(name,c.name);
    delete [] hobby;
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight = c.weight;

    return *this;
}

void Cow::ShowCow() const
{
    cout << "Name: " << name << endl;
    cout << "Hobby: " << hobby << endl;
    cout << "Weight: " << weight << endl;
}

int main()
{
    {
        Cow c0;
        Cow c1("Jack cow","running",896.8);
        Cow c2(c1);
        cout << "c0:\n";
        c0.ShowCow();
        cout << "c1:\n";
        c1.ShowCow();
        cout << "c2:\n";
        c2.ShowCow();
        c0 = c1;
        cout << "c0:\n";
        c0.ShowCow();
    }
}
