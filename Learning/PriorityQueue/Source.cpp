#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void max_heapify(int arr[], int i, int N) {
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left < N && arr[left] > arr[i])
		largest = left;
	if (right < N && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[largest], arr[i]);
		max_heapify(arr, largest, N);
	}
}

int maximum(int Arr[]) {
	return Arr[1];
}

int extract_maximum(int Arr[], int length) {
	if (length == 0) {
		cout << "Cannot remove as queue is empty";
		return -1;
	}
	int max = Arr[1];
	Arr[1] = Arr[length];
	length = length - 1;
	max_heapify(Arr, 1, length);
}

void increase_value(int Arr[], int i, int val) {
	if (val < Arr[i]) {
		cout << "New value is less than current value, cannot insert" << endl;
		return;
	}
	Arr[i] = val;
	while (i > 1 && Arr[i / 2] < Arr[i]) {
		swap(Arr[i / 2], Arr[i]);
		i = i / 2;
	}
}

void insert_value(int Arr[], int val, int length) {
	length = length + 1;
	Arr[length] = INT_MIN;
	increase_value(Arr, length, val);
}

int main() {
	//int Arr[] = { 0, 4, 7, 8, 9, 2, 6 };
	int Arr[10];
	insert_value(Arr, 8, 0);
	insert_value(Arr, 7, 1);
	insert_value(Arr, 6, 2);
	insert_value(Arr, 3, 3);
	insert_value(Arr, 1, 4);
	insert_value(Arr, 4, 5);
	extract_maximum(Arr, 6);
	return 0;
}