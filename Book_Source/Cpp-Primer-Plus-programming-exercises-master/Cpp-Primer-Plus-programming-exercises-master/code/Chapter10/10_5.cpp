// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>
#include<string>

using namespace std;

struct customer
{
    string fullname;
    double payment;
};

typedef customer Item;

class Stack
{
private:
    enum{MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item& item);
    bool pop(Item& item);
};

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty()const
{
    return top == 0;
}

bool Stack::isfull()const
{
    return top == MAX;
}

bool Stack::push(const Item& item)
{
    if(top < MAX){
        items[top++] = item;
        return true;
    }
    else return false;
}

bool Stack::pop(Item& item)
{
    if(top > 0){
        item = items[--top];
        return true;
    }
    else return false;
}

int main()
{
    customer cus[3];
    customer Acus;
    double total = 0.0;
    Stack Astack;
    cus[0].fullname = "Jack Ma";
    cus[0].payment = 33509.82;
    cus[1].fullname = "Robin Lee";
    cus[1].payment = 29475.83;
    cus[2].fullname = "Pony Ma";
    cus[2].payment = 39587.83;
    for(int i=0;i<3;++i) Astack.push(cus[i]);
    for(int i=0;i<3;++i){
        Astack.pop(Acus);
        total += Acus.payment;
        cout << total << endl;
    }

    return 0;
}
