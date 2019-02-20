/*
n���� ���ڰ� �־�����, �� �߿��� r���� ���ӵ� ���ڸ� �������� ��, �� ���� �κ� ������ ���ڰ� �ߺ����� �ʱ⸦ ���Ѵ�. ���� ���, ������ ���� 10���� ���ڿ��� 3���� ���ӵ� ���ڸ� ������ �� �ִ�.

�ߺ����±���

�̷��� ������ �ϸ�, ���õ� ���ڵ� ���̿����� �ߺ��� �������� �ʴ´�. r�� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, (4, 2, 1, 3)�� �����ϸ� �ǹǷ� r�� �ִ��� 4�̴�. r�� 5 �̻��� �� ���, �ߺ� ���� ���� �κ��� �����ϴ� ���� �Ұ����ϴ�.



�Է�
ù° �ٿ��� ������ ���� n�� �־�����. ( 1 �� n �� 100,000 ) ��° �ٿ� n���� ���ڰ� �־�����. �� ���ڴ� �׻� 1���� ũ�ų� ����, n���� �۰ų� ����.

���
r�� �ִ��� ����Ѵ�.



���� �Է�
10
1 3 1 2 4 2 1 3 2 1
���� ���
4


���� �Է�
7
7 1 4 2 5 3 6
���� ���
7*/
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int n;
int arr[100002];
int idx[100002];

bool check(int num) {
	int cnt = 0;
	set<int> s;

	for (int i = 0; i<num; i++) {
		s.insert(arr[i]);
		idx[arr[i]] = i;
	}
	if (s.size() == num) return true;

	for (int i = 0; i < n - num; i++) {
		s.insert(arr[i + num]);
		idx[arr[i + num]] = i + num;

		if (idx[arr[i]] == i) {
			s.erase(arr[i]);
		}

		if (s.size() == num) {
			return true;
		}
	}
	return false;
}
int main() {
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> arr[i];
	}

	int left = 1;
	int right = n + 1;

	while (left + 1<right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}

	}
	cout << left;
	return 0;
}