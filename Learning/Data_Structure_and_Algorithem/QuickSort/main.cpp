#include <iostream>
#include <array>
#include <algorithm>

template<size_t SIZE>
void print_arr(const std::array<int, SIZE> &arr) {
	for (int i = 0; i < SIZE; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << '\n';
}

template<size_t SIZE>
size_t partition(std::array<int, SIZE> &arr, int low, int high) {
	int i = low - 1;
	int pivot = arr[high];
	for (int j = low; j <= high; ++j) {
		if (arr[j] < pivot) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return (i + 1);
}

template<size_t SIZE>
void quick_sort(std::array<int, SIZE> &arr, int low, int high) {
	if (low < high) {
		int pos = partition(arr, low, high);
		quick_sort(arr, low, pos - 1);
		quick_sort(arr, pos + 1, high);
	}
}

int main() {
	std::array<int, 9> arr = { 7, 2, 1, 8, 2, 6, 3, 5, 4 };
	quick_sort(arr, 0, arr.size() - 1);
	print_arr(arr);

}