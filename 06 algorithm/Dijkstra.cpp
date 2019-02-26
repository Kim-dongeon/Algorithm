/*
8 11 0 6		정점, 간선, 시작점, 도착점
0 1 3
0 5 1
1 2 4
1 3 1
1 5 1
2 4 6
2 6 9
2 7 4
3 4 2
4 6 9
6 7 3

답 13
*/
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 100;

vector<int> graph[MAX];
vector <int> cost[MAX];

int n, m, start, end2;
int Table[MAX];
bool check[MAX];
int main() {

	scanf("%d %d %d %d", &n, &m, &start, &end2);

	for (int i = 0; i<m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(b);
		graph[b].push_back(a);

		cost[a].push_back(c);
		cost[b].push_back(c);

	}

	for (int i = 0; i<n; i++) {
		Table[i] = 987654321;
	}
	Table[start] = 0;

	for (int i = 0; i<n; i++) {
		//(1)최솟값을 구한다. 단, 지금까지 최단거리로 확정되지 않았던 정점에 대해서

		//(2)그 최솟값을 갖는 노드로부터 뻗어나간다.
		int minVal = 987654321, minIdx = -1;

		for (int j = 0; j<n; j++) {
			if (!check[j] && minVal > Table[j]) {
				minVal = Table[j];
				minIdx = j;
			}
		}

		cout << minIdx << endl;
		check[minIdx] = true;

		for (int j = 0; j<graph[minIdx].size(); j++) {
			int Node2 = graph[minIdx][j];
			int Cost2 = cost[minIdx][j];

			if (Table[Node2] > Table[minIdx] + Cost2) {
				Table[Node2] = Table[minIdx] + Cost2;
			}
		}
	}

	for (int i = 0; i<n; i++) printf("%d ", Table[i]);
	return 0;
}