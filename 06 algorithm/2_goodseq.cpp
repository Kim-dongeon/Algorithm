/* ��������
����
���� 1, 2, 3���θ� �̷������ ������ �ִ�. ������ ������ ������ �� ���� �κ� ������ ������ �� �� ������, �� ������ ���� �����̶�� �θ���. �׷��� ���� ������ ���� �����̴�.

������ ���� ������ ���̴�.

33

32121323

123123213

������ ���� ������ ���̴�.

2

32

32123

1232123

���̰� N�� ���� �������� N�ڸ��� ������ ���� ���� ���� ���� ���� ��Ÿ���� ������ ���ϴ� ���α׷� �� �ۼ��϶�. ���� ���, 1213121�� 2123212�� ��� ���� ���������� �� �߿��� ���� ���� ��Ÿ���� �� �� 1213121�̴�.



�Է�
�Է��� ���� N�ϳ��� �̷������. N�� 1 �̻� 80 �����̴�.



���
ù ��° �ٿ� 1, 2, 3���θ� �̷���� �ִ� ���̰� N�� ���� ������ �߿��� ���� ���� ���� ��Ÿ�� �� ������ ����Ѵ�. ������ �̷�� 1, 2, 3�� ���̿��� ��ĭ�� ���� �ʴ´�.



���� �Է�
7
���� ���
1213121
*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int arr[100];
bool stop = false;
bool promising(string str) {
	int str_len = str.size();
	int loop = str_len / 2;
	for (int i = 1; i <= loop; i++) {
		if (str.substr(str_len - i, i).compare(str.substr(str_len - i * 2, i)) == 0) {
			return false;
		}
	}

	return true;
}
void good_seq(int len, int N, string str) {
	if (stop) {
		return;
	}

	if (len == N) {
		cout << str;
		stop = true;
		return;
	}

	for (int i = 1; i<4; i++) {
		string tmp_str = str;
		tmp_str += to_string(i);
		if (promising(tmp_str)) {
			good_seq(len + 1, N, tmp_str);
		}
	}
}
int main() {
	int N;
	cin >> N;

	good_seq(0, N, "");
	return 0;
}