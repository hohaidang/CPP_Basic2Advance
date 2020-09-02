#include <iostream>
#include <map>
#include <mutex>
#include <numeric>
#include <thread>
#include <vector>
using namespace std;

int counter = 0;
void Incrementer() {
  for (size_t i = 0; i < 100; i++) {
      counter++;
  }
}

/* vi du nay cho ta thay, ta thuc hien 1000 lan, moi lan co 100 thread, moi thread cong counter 100 lan
   vay thi dang le ket qua tat ca 1000 lan phai ra gia tri la 10k, nhung se co 1 so lan thread nay chua cong xong
   thread khac da nhay vao cong, lay gia tri truoc, cho nen se ra gia tri chua toi 10k vd 9988, 9999*/
int main() {
    
    for(int i = 0; i < 1000; ++i) {
        vector<thread> v_threads;
        counter = 0;
        for (int i = 0; i < 100; i++) {
          v_threads.push_back(std::thread(Incrementer));
        }
        
        for (std::thread &t : v_threads) {
          t.join();
        }
        
        cout << counter << ",";
    }
    return 0;
}
