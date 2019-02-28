/*
����
N���� ������ �־��� ��, ���ӵ� �κ��� �����Ͽ� ���� �ִ�ȭ �ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, �Ʒ��� ���� 8���� ���ڰ� ���� ���, ��ĥ�� �κ��� �������� �� �� ���� ���� �ִ밡 �ȴ�.

���Ӻκ��ִ���



�Է�
ù ��° �ٿ� n�� �־�����. ( 1 �� n �� 100,000 ) �� ��° �ٿ� n���� ������ �־�����.



���
���ӵ� �κ��� �����Ͽ��� ���� �ִ��� ����Ѵ�.



���� �Է�
8
2 3 -5 8 -3 4 2 -9
���� ���
11*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100002];

int conquer(int start, int end) {
	//�ε��� start~end���� �� ���� ū �� return;

	if (start == end) {
		return arr[start];
	}

	int mid = (start + end) / 2;
	int left_max = conquer(start, mid);
	int right_max = conquer(mid + 1, end);

	int left_sum = 0;
	int left = -987654321;
	for (int i = mid; i >= start; i--) {
		left_sum += arr[i];
		left = max(left_sum, left);
	}
	int right = -987654321;
	int right_sum = 0;
	for (int i = mid + 1; i <= end; i++) {
		right_sum += arr[i];
		right = max(right_sum, right);
	}

	int mid_max = right + left;

	return max(max(mid_max, left_max), right_max);
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> arr[i];
	}

	cout << conquer(0, n - 1);

	return 0;
}