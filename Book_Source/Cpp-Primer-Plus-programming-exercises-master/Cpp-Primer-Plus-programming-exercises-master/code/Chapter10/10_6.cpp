// By luckycallor
// Welcome to my site: www.luckycallor.com

#include<iostream>

using namespace std;

class Move
{
private:
    double x;
    double y;
public:
    Move(double a=0,double b=0);
    void showmove()const;
    Move add(const Move& m) const;
    void reset(double a=0,double b=0);
};

Move::Move(double a,double b)
{
    x = a;
    y = b;
}

void Move::showmove() const
{
    cout << "(" << x << "," << y << ")";
}

Move Move::add(const Move& m)const
{
    Move temp(x+m.x,y+m.y);
    return temp;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

int main()
{
    cout << "Create move1 in a default way." << endl;
    Move move1;
    cout << "Create move2 in a initialized way." << endl;
    Move move2(1.1,3.5);
    cout << "Show move1: ";
    move1.showmove();
    cout << endl;
    cout << "Show move2: ";
    move2.showmove();
    cout << endl;
    cout << "Reset move1 to (5.8,8.6)." << endl;
    move1.reset(5.8,8.6);
    cout << "Show move1: ";
    move1.showmove();
    cout << endl;
    cout << "Add move1 and move2 to create move3." << endl;
    Move move3 = move1.add(move2);
    cout << "Show move3: ";
    move3.showmove();
    cout << endl;

    return 0;
}

