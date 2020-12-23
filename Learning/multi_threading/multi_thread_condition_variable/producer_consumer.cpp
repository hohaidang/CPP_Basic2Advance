#include <iostream>
#include <thread>
#include <random>
using namespace std;

auto get_random_value = std::bind(std::uniform_int_distribution<>(0, 1000),
                                std::default_random_engine());


mutex g_mutex;
condition_variable g_cv;
int g_data = 0;
bool g_ready = false;

/* g_cv.notify_one() la chi notify cho duy nhat 1 thread */
/* g_cv.notify_all() la notify cho tat ca cac threads*/

void consumer() {
    int data;
    for(int i = 0; i < 100; ++i) {
        unique_lock<mutex> ul(g_mutex);
        // the condition variable g_cv
        // if blocked, it will call ul.unclock() automatically
        // if unblocked, it will call ul.lock() automatically
        g_cv.wait(ul, [](){ return g_ready; }); // wait until g_ready = true and notified g_cv by producer
        data = g_data; // get data
        g_ready = false;
        cout << "data = " << data << endl;
        ul.unlock(); // khi call unlock() thi lock() ben thread producer se tu dong duoc goi. unclock() va lock() se duoc link voi nhau
        g_cv.notify_one();
        ul.lock();
    }
}

void producer() {
    for (int i = 0; i < 100; ++i) {
        unique_lock<mutex> ul(g_mutex);
        g_data = get_random_value();
        g_ready = true;
        ul.unlock();
        g_cv.notify_one(); // tell consumer that data is ready
        ul.lock();
        g_cv.wait(ul, [](){ return !g_ready; }); // w8 util g_ready = false and notified by consumer
    }

}

/* cau hoi dat ra la tai sao phan can dung 2 vien g_ready va g_cv?
   boi vi trong OS doi khi se tu dong goi g_cv.wait() ma khong duoc bat cu thread nao trigger notify.
   do do ta phai can bien g_ready de check xem la thread producer da lay duoc data chua. */

int main() {
    thread t1(producer);
    thread t2(consumer);
    
    t1.join();
    t2.join();
    return 0;
}
