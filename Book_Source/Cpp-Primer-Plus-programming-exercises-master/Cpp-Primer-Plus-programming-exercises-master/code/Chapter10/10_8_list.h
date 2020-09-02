// By luckycallor
// Welcome to my site: www.luckycallor.com

typedef int Item;

class List
{
private:
    static const int MAX = 40;
    Item items[MAX];
    int cnt;
public:
    List();
    bool Add(const Item& item);
    bool isEmpty() const;
    bool isFull() const;
    void visit(void (*pf)(Item&));
};


