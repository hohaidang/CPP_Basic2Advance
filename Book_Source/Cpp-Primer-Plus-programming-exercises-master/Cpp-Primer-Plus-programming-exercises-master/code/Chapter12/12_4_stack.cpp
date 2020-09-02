// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"12_4_stack.h"

Stack::Stack(const Stack& st)
{
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for(int i=0;i<size;++i) pitems[i] = st.pitems[i];
}

Stack::Stack(int n)
{
    size = n;
    top = 0;
    pitems = new Item[size];
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty()const
{
    return top == 0;
}

bool Stack::isfull()const
{
    return top == size;
}

bool Stack::push(const Item& item)
{
    if(top < size){
        pitems[top++] = item;
        return true;
    }
    else return false;
}

bool Stack::pop(Item& item)
{
    if(top > 0){
        item = pitems[--top];
        return true;
    }
    else return false;
}

Stack& Stack::operator=(const Stack& s)
{
    if(this == &s) return *this;
    delete [] pitems;
    size = s.size;
    top = s.top;
    pitems = new Item[size];
    for(int i=0;i<size;++i) pitems[i] = s.pitems[i];
    return *this;
}
