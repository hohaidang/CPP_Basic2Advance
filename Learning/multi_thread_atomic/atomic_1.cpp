#include <iostream>
#include <atomic>
using namespace std;

// Check out https://www.youtube.com/watch?v=IE6EpkT7cJ4&t=3s

int func(int a) {
	return a * 10 * 10;
}


/*Atomic giong nhu la mutex, se dam bao la khi ghi vao mot bien nao do thi nhung thread khac se khong the dong thoi ghi, 
  va khi read thi se khong co 1 thread nao dang duoc ghi. */
int main() {
	// load(), store()
	atomic<int> a{ 5 };
	int b = a.load(); // get a variable
	int c = 50;
	a.store(c); // store c variable into a
	cout << "b = " << b << endl;
	cout << "a = " << a.load() << endl;

	// exchange()
	atomic<int> atomic_x(1);
	int y = 2, z = 3;
	z = atomic_x.exchange(y);
	// exchange() equivalance to 
	// z = atomic_x
	// atomic_x = y
	cout << "z = " << z << endl << "y = " << y << endl << "atomic_x = " << atomic_x << endl;

	// compare_exchange_strong()
	atomic<int> atomic_i{ 1 };
	int expected = 2;
	int desired = 3;
	bool successful = atomic_i.compare_exchange_strong(expected, desired);
	// compare_exchange_strong() is equivalance to
	/* if(atomic_i == expected) {
			atomic_i = desired
			return true
	   }
	   else {
			expected = atomic_i
			return false
	   }*/
	cout << "successful = " << successful << ", expected = " << expected << ", atomic_i = " << atomic_i.load() << ", desired = " << desired << endl;
	

	// when using compare_exchange_strong()
	// gia su ta co 2 thread 
	/*T1 load()
	 |         T2 store()
	 |       /
	 |      /   
	func()   
	 |
	store()*/
	/*neu thread 1 chay truoc, update bien store(), co kha nang bien store o thread 2 se bi miss*/
	/*do do' giai phap la dung pattern, load bien old_k truoc, sau do check neu old_k bi thay doi boi thread 2 thi ta se update lai old_k moi va chay lai vong for voi T1*/
	atomic<int> atomic_k{ 5 };
	auto old_k = atomic_k.load();
	while (atomic_k.compare_exchange_strong(old_k, func(atomic_k)) == false); // chua hieu compare_exchange_strong and weak
	cout << "atomic_k = " << atomic_k.load();


	// lock free
	atomic<int> test_lock_free{5};
	cout << boolalpha << "Is atomic test_lock_free is lock free? " << test_lock_free.is_lock_free() << endl;
	cout << boolalpha << "Is atomic test_lock_free is always lock free? " << test_lock_free.is_always_lock_free << endl;
	return 0;
}