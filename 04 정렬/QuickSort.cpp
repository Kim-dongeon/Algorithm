#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int arr[10];

void printArr(int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void quick_sort(int pivot, int left, int right) {
	int left_idx = left;
	int right_idx = right;

	while (left_idx <= right_idx) {

		while (left_idx <= right && arr[pivot] >= arr[left_idx]) {
			left_idx++;
		}
		while (right_idx >= left && arr[pivot] <= arr[right_idx]) {
			right_idx--;
		}

		if (left_idx <= right_idx) {
			swap(arr[left_idx], arr[right_idx]);
		}
		else {
			swap(arr[pivot], arr[right_idx]);
			quick_sort(pivot, pivot + 1, right_idx - 1);
			quick_sort(right_idx + 1, right_idx + 2, right);
		}
	}

}
int main() {
	srand((unsigned int)time(NULL));

	for (int t = 0; t < 10; t++) {
		cout << "#" << t << "===============" << endl;
		for (int i = 0; i < 10; i++) {
			arr[i] = rand() % 100;
		}
		int n = 10;
		printArr(n);
		quick_s(0, 1, n - 1);
		printArr(n);
	}

}