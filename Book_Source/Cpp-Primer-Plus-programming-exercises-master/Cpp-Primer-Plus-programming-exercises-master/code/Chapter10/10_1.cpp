// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

class BANK_ACCOUNT
{
private:
    string name;
    string acnt_id;
    double money;
public:
    BANK_ACCOUNT(string na = "no name",string id = "00000000",double m = 0.0);
    BANK_ACCOUNT(const BANK_ACCOUNT& that);
    ~BANK_ACCOUNT();
    bool save_money(double x);
    bool take_money(double x);
    void show()const;
};

BANK_ACCOUNT::BANK_ACCOUNT(const BANK_ACCOUNT& that)
{
    name = that.name;
    acnt_id = that.acnt_id;
    money = that.money;
}


BANK_ACCOUNT::BANK_ACCOUNT(string na, string id, double m)
{
    name = na;
    acnt_id = id;
    money = m;
}

BANK_ACCOUNT::~BANK_ACCOUNT()
{
    cout << name << "' account " << acnt_id << " deleted!" << endl;
}

bool BANK_ACCOUNT::save_money(double x)
{
    if(x < 0) return false;
    else{
        money += x;
        return true;
    }
}

bool BANK_ACCOUNT::take_money(double x)
{
    if(x < 0) return false;
    else if(x > money) return false;
    else{
        money -= x;
        return true;
    }
}

void BANK_ACCOUNT::show()const
{
    cout << "Name: " << name << endl;
    cout << "   Account id: " << acnt_id << endl;
    cout << "   Money in account: $" << money << endl;
}

int main()
{
    {
        BANK_ACCOUNT acnt = BANK_ACCOUNT("luckycallor","20151113",0.0);
        cout << "Account information:" << endl;
        acnt.show();
        cout << "Save $100.1" << endl;
        acnt.save_money(100.1);
        acnt.show();
        cout << "Take $53.2" << endl;
        acnt.take_money(53.2);
        acnt.show();
    }
    return 0;
}

