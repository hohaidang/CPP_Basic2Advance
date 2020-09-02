// By luckycallor
// Welcome to my site: www.luckycallor.com

#include "stdafx.h"
#include"14_3_worker.h"
#include<iostream>
#include<cstring>

using namespace std;

const int SIZE = 5;

template<class T>
class QueueTp
{
private:
    T* items;
    int num;
    int Max;
public:
    QueueTp(int n = SIZE):Max(n),num(0){items = new T[Max];}
    QueueTp(const QueueTp& qt);
    ~QueueTp(){delete [] items;}
    T& header(){if(num > 0) return items[num-1];}
    const T& header()const{if(num > 0) return items[num-1];}
    bool isEmpty()const {return num == 0;}
    bool isFull()const {return num == Max;}
    bool enQueue(const T& item);
    bool deQueue(T& item);
    QueueTp& operator=(const QueueTp& qt);
};

template<class T>
QueueTp<T>::QueueTp(const QueueTp& qt)
{
    num = qt.num;
    Max = qt.Max;
    items = new T[Max];
    for(int i=0;i<num;++i) items[i] = qt.items[i];
}

template<class T>
bool QueueTp<T>::enQueue(const T& item)
{
    if(num == Max) return false;
    items[num++] = item;
    return true;
}

template<class T>
bool QueueTp<T>::deQueue(T& item)
{
    if(num == 0) return false;
    item = items[--num];
    return true;
}

template<class T>
QueueTp<T>& QueueTp<T>::operator=(const QueueTp& qt)
{
    if(this == &qt) return *this;
    delete [] items;
    num = qt.num;
    Max = qt.Max;
    items = new T[Max];
    for(int i=0;i<num;++i) items[i] = qt.items[i];
    return *this;
}

int main()
{
    QueueTp<Worker*> lolas(SIZE);

    int ct;
    for(ct = 0;ct < SIZE;++ct){
        char choice;
        cout << "Enter the employee category:\n"
        << "w: waiter  s: singer  "
        << "t: singing waiter  q: quit\n";
        cin >> choice;
        while(strchr("wstq",choice) == NULL){
            cout << "Please enter a w,s,t or q: ";
            cin >> choice;
        }
        if(choice == 'q') break;
        switch(choice)
        {
            case 'w': lolas.enQueue(new Waiter);
            break;
            case 's': lolas.enQueue(new Singer);
            break;
            case 't': lolas.enQueue(new SingingWaiter);
            break;
        }
        cin.get();
        lolas.header()->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    Worker* temp;
    while(lolas.deQueue(temp)){
        cout << endl;
        temp->Show();
        delete temp;
    }
    cout << "Bye.\n";
    return 0;
}
