/*문제
무방향 그래프가 주어질 때, 정점 1번에서 정점 N번으로 가는 최단거리를 구하려 하는데, 그 과정에서 두 개의 정점을 반드시 거쳐야 한다.한 번 방문했던 정점을 또 다시 방문하는 것도 허용하고, 간선도 마찬가지로 여러번 방문하는 것을 허용한다고 할 때, 1번에서 N번으로 가는 “특정한" 최단거리를 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1, 000, 1 ≤ M ≤ 100, 000) 둘째 줄부터 간선의 정보가 주어진다.각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a와 정점 b가 가중치 c인 간선으로 연결되어 있다는 의미이다.마지막 줄에는 반드시 거쳐야 하는 두 정점 A, B가 주어진다. (1 ≤ a, b, A, B ≤ 1, 000, 1 ≤ c ≤ 50, 000)
출력
1번 정점에서 N번 정점으로 가는 “특정한" 최단거리를 출력한다. 단, “특정한" 최단거리란, 주어진 정점 A와 B를 반드시 방문할 때의 최단거리를 의미한다.
예제 입력
4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3
예제 출력
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