/*
����
Ʈ���� ��� X�� ���Ͽ� ������"�� ������ �� �ִ�. X�� ������"�̶�, ��Ʈ���� �ö󰡴� �߿� ������ ��� ��带 ���Ѵ�. ���� ���, �Ʒ��� ���� Ʈ���� �־��� ���, ��� 8�� ������"�� ��� 0, ��� 2, ��� 6�� �ȴ�.

alt text

�� ��� X, Y�� ���� �����̶�, X�� Y�� �������� ���� ������ ���Ѵ�. ���� ���, ��� 7�� ��� 10�� ���������� ��� 2, ��� 0�� �ȴ�. ���� ����� ���� �����̶�, X�� Y�� �������� ���� ����� �߿��� X, Y�� ���� ����� ������ ���Ѵ�. ���� ���, ��� 7�� ��� 10�� ���� ����� ���� ������ ��� 2�� �ȴ�. Ʈ���� �־�����, �� ��� X, Y�� �־��� ��, ���� ����� ���� ������ ã�� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù ��° �ٿ� Ʈ���� ��� ���� n, �� ��� X, Y�� ��ȣ�� �־�����. ( 1 �� X, Y �� n �� 1000 ) �� ��° �ٺ��� Ʈ���� ���� ������ �־�����. �� ���� 2���� ���� a, b�� �̷������, �̴� ��� a�� ��� b�� �θ����� ���� �ǹ��Ѵ�. ��Ʈ�� ��� 0�̶�� �����Ѵ�.

���
�� ��� X, Y�� ���� ������ ����Ѵ�.



���� �Է�
11 7 10
0 1
0 2
1 3
1 4
1 5
2 6
2 10
6 7
6 8
6 9
���� ���
2

*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> tree[1002];
int depth[1002];
int parent[1002];
bool visited[1002];
void makeTree(int node) {
	visited[node] = true;
	for (int child : tree[node]) {
		if (!visited[child]) {
			depth[child] = depth[node] + 1;
			parent[child] = node;
			makeTree(child);
		}
	}
}
int main() {
	int N, X, Y;
	cin >> N >> X >> Y;
	for (int i = 0; i<N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	parent[0] = -1;
	makeTree(0);

	while (depth[X]>depth[Y]) {
		X = parent[X];
	}
	while (depth[X] < depth[Y]) {
		Y = parent[Y];
	}

	while (X != Y) {
		X = parent[X];
		Y = parent[Y];
	}
	cout << X;
	return 0;
}