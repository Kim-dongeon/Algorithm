/*
����
ö���� �������� N���� ���� ������, �� ���� ������ ��ȣ�� �ο��޴´�. �� ��ȣ�� 1���� ũ�ų� ����, N���� �۰ų� ����. ö���� ���� K�� ��� �ִ�. ���� �� ���̿��� �ܹ��� ���ΰ� �����ϱ� ������, �� ���θ� ���Ͽ� ���� �̵��� �� �ִ�. ��, N���� ������ �׷��� ������ �̷��. ���ǻ� �� ������ �� ������� ��� �ִٰ� ��������. ũ���������� ����, ö���� ������ ������ ��Ƽ�� ������ �Ѵ�. ���� �ٸ� ��� ������� ö���� ���� �� ��Ƽ�� ����, ��Ƽ�� ���� �Ŀ��� �ٽ� ������ ������ ���ư��� �Ѵ�. ������� ������ ������ ö���� ������ �̵��ϱ� ���Ͽ� �׻� �ִܰŸ��� �̵��ϱ⸦ ���ϰ�, ���������� ö���� ������ ������ ���� �� ���� �ִܰŸ��� �̵��ϱ⸦ ���Ѵ�. ���� ������ �� ���� �մ� �ܹ��� ������ ����, �׸��� ö���� �� ��ȣ�� �־��� ��, ���� ������� ��Ƽ�� ���� ���ؼ� �̵��ؾ� �ϴ� �� �Ÿ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù° �ٿ� ������ ���� N�� ������ ���� M, �׸��� ö���� �� ��ȣ K�� �־�����. ( 1 �� N, K �� 1,000, 1 �� M �� 100,000 ) ��° �ٺ��� ������ ������ �־�����. �� ���� �� ���� ���� a, b, c�� �̷���� ������, �̴� ���� a���� ���� b�� �̵��ϴ� �� �ð��� c��ŭ �ɸ��ٴ� �ǹ��̴�. ����� ���ΰ� �ƴԿ� ��������.



���
���� ������� ��Ƽ�� ���� ���ؼ� �̵��ؾ� �ϴ� �� �Ÿ��� ���� ����Ѵ�.



���� �Է�
6 10 3
1 2 1
2 5 2
3 1 5
3 2 3
3 4 1
3 6 4
4 1 1
5 3 1
6 5 3
6 4 2


���� ���
32
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, K;
vector<int> graph[1002];
vector<int> reverseGraph[1002];
vector<int> cost[1002];
vector<int> cost2[1002];
int table[1002];
bool isVisited[1002];


int getCal(vector<int> v[1002], vector<int> c[1002]) {

	memset(isVisited, false, sizeof(bool)*(N + 1));
	for (int i = 1; i <= N; i++) {
		table[i] = 987654321;
	}
	table[K] = 0;

	for (int i = 1; i <= N; i++) {
		int minIdx = -1;
		int minVal = 987654321;

		for (int j = 1; j <= N; j++) {
			if (isVisited[j] == false) {
				if (minVal > table[j]) {
					minIdx = j;
					minVal = table[j];
				}
			}
		}

		isVisited[minIdx] = true;

		for (int j = 0; j<v[minIdx].size(); j++) {
			int node2 = v[minIdx][j];
			int cost2 = c[minIdx][j];

			if (table[node2] > table[minIdx] + cost2) {
				table[node2] = table[minIdx] + cost2;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		sum += table[i];
	}
	return sum;

}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i<M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(b);
		reverseGraph[b].push_back(a);
		cost[a].push_back(c);
		cost2[b].push_back(c);
	}

	int ans = 0;
	ans += getCal(graph, cost);
	ans += getCal(reverseGraph, cost2);

	cout << ans;
	return 0;
}