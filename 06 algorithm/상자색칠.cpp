/*����
���� 6���� ���ڰ� �ִ�.�̸� ���� ���� ������ ĥ�Ϸ� �ϴµ�, �� ������ �ִ�.���� ������ ������ �鿡 ĥ�ϸ� �� �ȴٴ� ���̴�.���� ���� ������ �־����� ��, �� ������ ������ �����Ͽ� ������ ��� ���� ĥ�� �� �ִ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N(1 <= N <= 1, 000) �� �־�����.��° �ٿ� ������ ��Ÿ���� N���� ���ڰ� �־�����.������ ���� ������ �̷���� �ְ�, 1���� N������ ������ ���̴�.

���
������ �����ϸ鼭 ���ڸ� ĥ�� �� ������ ��YES��, �ƴϸ� ��NO���� ����Ѵ�.

���� �Է�
6
1 1 1 2 2 3
���� ���
NO

���� �Է�
6
1 2 3 4 5 6
���� ���
YES

���� �Է�
8
1 2 2 2 1 1 1 3
���� ���
NO
*/
#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int main() {

	bool flag = true;
	set<int> s;
	int N;
	scanf("%d", &N);

	int chk[1002] = { 0, };
	for (int i = 0; i<N; i++) {
		int color;
		scanf("%d", &color);
		s.insert(color);
		chk[color]++;
	}

	int sz = s.size();
	int two = 0;
	for (int i = 1; i <= N; i++) {
		if (chk[i] >= 2) {
			two++;
		}
	}
	if (sz >= 6) {
		cout << "YES";
	}
	else if (sz >= 3 && sz <= 5) {
		if (two >= 6 - sz) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
	return 0;
}