#include <iostream>
using namespace std;
 
// bai nay noi ve function overload operator

class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
      
   public:
      // required constructors
      Distance() {
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i) {
         feet = f;
         inches = i;
      }
      
      // overload function call
      Distance operator()(int a, int b, int c) {
         Distance D;
         
         // just put random calculation
         D.feet = a + c + 10;
         D.inches = b + c + 100 ;
         return D;
      }
    
    Distance operator()() const {
        Distance D;
        D.feet = 5;
        D.inches = 10;
        return D;
    }
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet << " I:" << inches << endl;
      }
};

int main() {
   Distance D1(11, 10), D2;

   cout << "First Distance : ";
   D1.displayDistance();

   D2 = D1(10, 10, 10); // goi operator()(int, int ,int)
   cout << "Second Distance :";
   D2.displayDistance();
    
    Distance D3;
    D3 = D1(); // goi opertor()(void);

   return 0;
}
