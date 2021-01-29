 #include <iostream>

template<typename Serializer>
void prettyPrint(Serializer& ser) {
    ser << "Dang Dep trai";
}

 int main() {
     prettyPrint(std::cout);
     return 0;
 }
