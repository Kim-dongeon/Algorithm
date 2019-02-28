/*
����
SCC (Strongly Connected Component)��, ���⼺ �׷����� �־��� �� ������ ���� �������� ������ ������ν�, ���� ���տ� �����ִ� ���������� ���� �Դٰ��� �� �� �־�� �Ѵ�. �Ʒ� �׸��� �׷����� ������, �� �׷������� SCC�� ���� �����̴�.

ec-24

�Ʒ� �׸�ó��, ������ {1, 2, 5}, {6, 7}, {3, 4, 8} �� 3���� �������� ������ �Ǹ�, ���� ���տ� ���� �����鳢���� ��� �Դٰ��� �� �� �ִ�. �׷����� �־��� ��, SCC�� ���Ͽ��� �� ���� �� �ִ� ������ ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 1,000, 1 �� M �� 100,000 ) ��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a���� ���� b�� ���ϴ� ������ �����Ѵٴ� �ǹ��̴�.



���
�־��� �׷������� SCC�� ���Ͽ��� ��, ���� �� �ִ� ������ ������ ������ ����Ѵ�.



���� �Է�
8 14
1 5
2 1
2 3
2 6
3 4
3 8
4 3
4 8
5 2
5 6
6 7
7 3
7 6
8 4

���� ���
3
*/

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[1002];
vector<int>reverse_graph[1002];
bool isVisited[1002];

int order[1002];
int order_idx;

int group[1002];
int group_cnt = 1;


int N, M;

void getPriority(int node) {
	isVisited[node] = true;

	for (int i = 0; i<graph[node].size(); i++) {
		int node2 = graph[node][i];

		if (!isVisited[node2]) {
			getPriority(node2);
		}
	}

	order[order_idx++] = node;
}

void getGroup(int node) {
	isVisited[node] = true;
	group[node] = group_cnt;

	for (int i = 0; i<reverse_graph[node].size(); i++) {
		int node2 = reverse_graph[node][i];

		if (!isVisited[node2]) {
			getGroup(node2);
		}
	}


}
int main() {

	cin >> N >> M;

	for (int i = 0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		reverse_graph[b].push_back(a);

	}

	for (int i = 1; i <= N; i++) {
		if (!isVisited[i]) {
			getPriority(i);
		}
	}

	memset(isVisited, false, sizeof(bool)*(N + 1));

	for (int i = order_idx - 1; i >= 0; i--) {
		if (!isVisited[order[i]]) {
			getGroup(order[i]);
			group_cnt++;
		}
	}

	cout << group_cnt - 1;
	return 0;
}