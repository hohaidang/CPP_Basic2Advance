#include <iostream>

using std::cout;
using std::endl;

void change(const int *pt, int n) {
  int *pc;
  // Const_cast will ignore the const in arguments and modify value
  // But const_cast cannot modify value has const define
  pc = const_cast<int *>(pt);
  *pc += n;
}

int main() {
  int pop1 = 30000;
  const int pop2 = 2000;
  cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
  change(&pop1, -103);
  change(&pop2, -103);
  cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
  return 0;
}