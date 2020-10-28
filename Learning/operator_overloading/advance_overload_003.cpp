#include <iostream>
#include <memory>

class MxAHDLine {

};

template<class T> class ZmRef {
public:
  inline ZmRef(T *o) : m_object(o) {
    //if (o) ZmObject_REF(o);
  }

  inline operator T *() const { return m_object; }
  T* m_object;
};

class MxAHD_Connection {
    //MxAHDLine *m_line = new MxAHDLine[2];
	MxAHDLine *m_line;
	
public:
    void rcvd() {
        ZmRef<MxAHDLine> line = m_line;
        if(!line) {
            std::cout << "line is null";
        }
        else {
            std::cout << "line is not null";
        }
    }
};


int main(){
    MxAHD_Connection temp;
    temp.rcvd();

    return 0;
}