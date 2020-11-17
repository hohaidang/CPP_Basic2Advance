#include <iostream>
#include <vector>
using namespace std;

// consider an actual class.
class Obj{
    static int i, j;
public:
    void f() const { cout << i++ << endl; }
    void g() const { cout << j++ << endl; }
};

// static member definitions
int Obj::i = 10;
int Obj::j = 12;

// Implement a container for the above class
class ObjContainer {
    vector<Obj *> a;
public:
    void add(Obj *obj) {
        a.push_back(obj); // call vector's standard method;
    }
    friend class SmartPointer;
};

class SmartPointer {
    ObjContainer oc;
    int index;
public:
    SmartPointer(ObjContainer &objc) {
        oc = objc;
        index = 0;
    }

    // return value indicates end of list:
    bool operator++() { // Prefix version
        if(index >= oc.a.size()) return false;
        if(oc.a[++index] == 0) return false;
        return true;
    }

    bool operator++(int) { // Postfix version
        return operator++();
    }

    // overload operator->
    Obj* operator->() const {
        if(!oc.a[index]) {
            cout << "Zero value";
            return (Obj*) 0;
        }
        return oc.a[index];
    }
};

int main() {
    const int sz = 10;
    Obj o[sz];
    ObjContainer oc;
    for(int i = 0; i < sz; ++i) {
        oc.add(&o[i]);
    }

    SmartPointer sp(oc);
    do {
        sp->f(); // call smart pointer
        // = sp.oc.a[index] call f() function
        sp->g();
    } while(sp++); // increase index
    return 0;
}