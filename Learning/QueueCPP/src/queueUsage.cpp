#include <iostream>
#include <queue>
using namespace std;

int temp3(){
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	if(q.empty()) {
		cout << "Queue is empty" << endl;
		return 0;
	}
	q.pop();
	cout << "First element: " << q.front() << endl;
	cout << "Last element: " << q.back() << endl;
	cout << "The size is: " << q.size() << endl;
	return 0;
}
