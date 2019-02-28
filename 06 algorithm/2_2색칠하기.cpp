/*
2�� ĥ�ϱ��, ���� �� ������ �����ϸ鼭 �׷����� ������ ��� ��ĥ�� �� �ִ��� ���� �����̴�. 2���� ���� �����Ѵ�. ������ �� ������ ������ �ٸ���. �׷����� �־��� ��, 2�� ĥ�ϱⰡ �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���, �Ʒ��� �׷����� 2�� ĥ�ϱⰡ ������ �׷����̸�, ������ ��ĥ�� ����� ������ ����.

ec-13



�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 10,000, 1 �� M �� 100,000 ) ��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�.(0 �� a, b �� N-1)



���
�־��� �׷����� ���Ͽ� 2�� ĥ�ϱ⸦ �� �� ������ YES, �� �� ������ NO�� ����Ѵ�.



���� �Է�
9 10
0 1
0 2
0 3
1 5
2 5
3 4
5 6
5 8
6 7
7 8
���� ���
YES*/
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr[10002];
int isVisited[10002];

bool stop;

bool dfs(int node, int color) {
	isVisited[node] = color;

	for (int i = 0; i<arr[node].size(); i++) {
		if (isVisited[arr[node][i]] == 0) {
			if (!dfs(arr[node][i], color % 2 + 1))
				return false;
		}
		else {
			if (isVisited[node] == isVisited[arr[node][i]]) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin >> N >> M;

	for (int i = 0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	if (dfs(0, 1)) {
		cout << "YES";
	}
	else
		cout << "NO\n";
	return 0;
}