/*����
������ �׷����� �־��� ��, ���� 1������ ���� N������ ���� �ִܰŸ��� ���Ϸ� �ϴµ�, �� �������� �� ���� ������ �ݵ�� ���ľ� �Ѵ�.�� �� �湮�ߴ� ������ �� �ٽ� �湮�ϴ� �͵� ����ϰ�, ������ ���������� ������ �湮�ϴ� ���� ����Ѵٰ� �� ��, 1������ N������ ���� ��Ư����" �ִܰŸ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. (1 �� N �� 1, 000, 1 �� M �� 100, 000) ��° �ٺ��� ������ ������ �־�����.�� ���� �� ���� ���� a, b, c�� �̷���� ������, �̴� ���� a�� ���� b�� ����ġ c�� �������� ����Ǿ� �ִٴ� �ǹ��̴�.������ �ٿ��� �ݵ�� ���ľ� �ϴ� �� ���� A, B�� �־�����. (1 �� a, b, A, B �� 1, 000, 1 �� c �� 50, 000)
���
1�� �������� N�� �������� ���� ��Ư����" �ִܰŸ��� ����Ѵ�. ��, ��Ư����" �ִܰŸ���, �־��� ���� A�� B�� �ݵ�� �湮�� ���� �ִܰŸ��� �ǹ��Ѵ�.
���� �Է�
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3
���� ���
7
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[1002];
bool isVisited[1002];
int table[1002];
vector<int> cost[1002];

int N, M;
int A, B;

int getCal(int start, int dst) {
	memset(isVisited, false, sizeof(bool)*(N + 1));
	for (int i = 1; i <= N; i++) {
		table[i] = 987654321;
	}
	table[start] = 0;

	for (int i = 1; i <= N; i++) {
		int minVal = 987654321;
		int minIdx = -1;

		for (int j = 0; j<N; j++) {
			if (!isVisited[j] && table[j] < minVal) {
				minIdx = j;
				minVal = table[j];
			}
		}

		isVisited[minIdx] = true;
		if (minIdx == dst) {
			return table[dst];
		}
		for (int j = 0; j<graph[minIdx].size(); j++) {
			int node2 = graph[minIdx][j];
			int cost2 = cost[minIdx][j];

			if (table[node2] > cost2 + table[minIdx]) {
				table[node2] = cost2 + table[minIdx];
			}
		}
	}

	return table[dst];
}
int main() {

	cin >> N >> M;
	for (int i = 0; i<M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(b);
		graph[b].push_back(a);

		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	cin >> A >> B;
	int ans = 0;
	int q = getCal(1, A);
	int e = getCal(B, N);
	int r = getCal(1, B);
	int t = getCal(A, N);

	cout << min(q + e, r + t) + getCal(A, B);
	return 0;
}