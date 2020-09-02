// By luckycallor
// Welcome to my site: www.luckycallor.com

#include"10_8_list.h"

List::List()
{
    cnt = 0;
}

bool List::Add(const Item& item)
{
    if(cnt < MAX) {
        items[cnt++] = item;
        return true;
    }
    else return false;
}

bool List::isEmpty()const
{
    return cnt == 0;
}

bool List::isFull()const
{
    return cnt == MAX;
}

void List::visit(void (*pf)(Item&))
{
    for(int i=0;i<cnt;++i) (*pf)(items[i]);
}


