// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

class Cpmv
{
public:
    struct Info
    {
        string qcode;
        string zcode;
    };
private:
    Info *pi;
public:
    Cpmv();
    Cpmv(string q,string z);
    Cpmv(const Cpmv& cp);
    Cpmv(Cpmv&& mv);
    ~Cpmv();
    Cpmv& operator=(const Cpmv& cp);
    Cpmv& operator=(Cpmv&& mv);
    Cpmv operator+(const Cpmv& obj) const;
    void Display()const;
};

Cpmv::Cpmv()
{
    pi = NULL;
    cout << "Default constructor used\n";
}

Cpmv::Cpmv(string q,string z)
{
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;
    cout << "String constructor used\n";
}

Cpmv::Cpmv(const Cpmv& cp)
{
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cout << "Copy constructor used\n";
}

Cpmv::Cpmv(Cpmv&& mv)
{
    pi = mv.pi;
    mv.pi = NULL;
    cout << "Move constructor used\n";
}

Cpmv::~Cpmv()
{
    delete pi;
    cout << "Destructor used\n";
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
    if(this == &cp) {
        cout << "Copy = used\n";
        return *this;
    }
    if(pi == NULL) pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    cout << "Copy = used\n";
    return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)
{
    delete pi;
    pi = mv.pi;
    mv.pi = NULL;
    cout << "Move = used\n";
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj)const
{
    Cpmv temp(pi->qcode+obj.pi->qcode,pi->zcode+obj.pi->zcode);
    cout << "+ used\n";
    return temp;
}

void Cpmv::Display()const
{
    if(pi == NULL){
        cout << "Info empty.\n";
        return;
    }
    cout << "Info: " << pi << endl;
    cout << "qcode: " << pi->qcode << endl;
    cout << "zcode: " << pi->zcode << endl;
}

int main()
{

    {
        Cpmv c1;
        c1.Display();
        Cpmv c2("qcode_value_","zcode_value_");
        c2.Display();
        Cpmv c3(c2);
        c3.Display();
        Cpmv c4(c2+c3);
        c4.Display();
        c1 = c4;
        c1.Display();
        c2 = c1 + c3;
        c2.Display();
    }
    return 0;
}


