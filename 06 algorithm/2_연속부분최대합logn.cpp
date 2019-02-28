/*
문제
N개의 정수가 주어질 때, 연속된 부분을 선택하여 합을 최대화 하는 프로그램을 작성하시오. 예를 들어, 아래와 같이 8개의 숫자가 있을 경우, 색칠된 부분을 선택했을 때 그 합이 가장 최대가 된다.

연속부분최대합



입력
첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 두 번째 줄에 n개의 정수가 주어진다.



출력
연속된 부분을 선택하였을 때의 최댓값을 출력한다.



예제 입력
8
2 3 -5 8 -3 4 2 -9
예제 출력
11*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100002];

int conquer(int start, int end) {
	//인덱스 start~end까지 중 가장 큰 값 return;

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