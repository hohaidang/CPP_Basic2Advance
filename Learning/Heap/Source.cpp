#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void max_heapify(int Arr[], int i, int N) {
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;
	if (left < N and Arr[left] > Arr[i]) {
		largest = left;
	}

	if (right < N and Arr[right] > Arr[largest])
		largest = right;

	if (largest != i) {
		swap(Arr[i], Arr[largest]);
		max_heapify(Arr, largest, N);
	}
}

void build_maxheap(int Arr[], int N) {
	for (int i = N / 2; i >= 1; --i) {
		max_heapify(Arr, i, N);
	}
}

int main() {
	int Arr[] = {0, 4, 7, 8, 9, 2, 6, 5 };
	build_maxheap(Arr, 8);
	return 0;
}