#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[10];
int _max = -999;
void r_rotate(int _arr[], int s, int t) {
	int temp = _arr[t];

	for (int i = t; i > s; i--) {
		_arr[i] = _arr[i - 1];
	}
	_arr[s] = temp;
}
void l_rotate(int _arr[], int s, int t) {
	int temp = _arr[s];
	for (int i = s; i < t; i++) {
		_arr[i] = _arr[i + 1];
	}
	_arr[t] = temp;
}
void perm(int set[], int size,int N, int K) {

	if (K == 0) {
		int sum = 0;
		for (int i = 0; i < N-1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
		}
		_max = max(sum, _max);
		return;
	}
	for (int i = size; i < N; i++) {
		r_rotate(set, size,i);
		perm(set, size + 1, N, K - 1);
		l_rotate(set, size, i);
	}
	
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	perm(arr, 0, N, N);
	printf("%d\n", _max);
}