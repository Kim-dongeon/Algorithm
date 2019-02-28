/*
문제
SCC (Strongly Connected Component)란, 방향성 그래프가 주어질 때 정점을 여러 집합으로 나누는 기법으로써, 같은 집합에 속해있는 정점끼리는 서로 왔다갔다 할 수 있어야 한다. 아래 그림은 그래프의 예제와, 이 그래프에서 SCC를 구한 예제이다.

ec-24

아래 그림처럼, 정점을 {1, 2, 5}, {6, 7}, {3, 4, 8} 의 3개의 집합으로 나누게 되면, 같은 집합에 속한 정점들끼리는 모두 왔다갔다 할 수 있다. 그래프가 주어질 때, SCC를 구하였을 때 얻을 수 있는 정점의 집합의 개수를 구하는 프로그램을 작성하시오.



입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 1,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a에서 정점 b로 향하는 간선이 존재한다는 의미이다.



출력
주어진 그래프에서 SCC를 구하였을 때, 얻을 수 있는 정점의 집합의 개수를 출력한다.



예제 입력
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

예제 출력
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