#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

bool Prime[1000001];

int main() {
	int n;
	scanf("%d", &n);

	//���� �����ﰢ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
	//���� �����ﰢ�� �Ųٷ�
	for (int i = 0; i < n; i++) {
		for (int j = n - i; j >= 1; j--) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
	//������ �����ﰢ��
	for (int i = 0; i < n; i++) {
		for (int j = n - 1 - i; j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j <= i; j++) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
	//������ �����ﰢ�� �Ųٷ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = n - i; j > 0; j--) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;

	//Ʈ�����
	for (int i = 0; i < n; i++) {
		for (int j = n - 1 - i; j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
	//�� Ʈ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int j = 0; j < (n - i) * 2 - 1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;
	//������
	for (int i = 0; i < n; i++) {
		for (int j = n - 1 - i; j > 0; j--) {
			cout << ' ';
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j <= i; j++) {
			cout << ' ';
		}
		for (int j = (n - 1 - i) * 2 - 1; j > 0; j--) {
			cout << '*';
		}
		cout << endl;
	}
	cout << endl;

	//A���
	for (int i = 0; i < n; i++) {
		for (int j = n - 1 - i; j > 0; j--) {
			cout << ' ';
		}
		if (i == n / 2) {
			for (int j = 0; j < 2 * i + 1; j++) {
				cout << '*';
			}
		}
		else {
			int k = 2 * i + 1;
			for (int j = 1; j <= 2 * i + 1; j++) {
				if (j == 1 || j%k == 0) {
					cout << '*';
				}
				else {
					cout << ' ';
				}

			}
		}

		cout << endl;
	}
	cout << endl;

	//�׸� ���
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) {
			for (int j = 0; j < n; j++) {
				cout << '*';
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (j == 0 || j == n - 1) {
					cout << '*';
				}
				else {
					cout << ' ';
				}
			}
		}
		cout << endl;
	}

}