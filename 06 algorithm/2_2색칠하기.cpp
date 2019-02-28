/*
2색 칠하기란, 다음 두 조건을 만족하면서 그래프의 정점을 모두 색칠할 수 있는지 묻는 문제이다. 2개의 색이 존재한다. 인접한 두 정점은 색깔이 다르다. 그래프가 주어질 때, 2색 칠하기가 가능한지 출력하는 프로그램을 작성하시오. 예를 들어, 아래의 그래프는 2색 칠하기가 가능한 그래프이며, 정점을 색칠한 결과는 다음과 같다.

ec-13



입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 100,000 ) 둘째 줄부터 간선의 정보가 주어진다. 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다.(0 ≤ a, b ≤ N-1)



출력
주어진 그래프에 대하여 2색 칠하기를 할 수 있으면 YES, 할 수 없으면 NO를 출력한다.



예제 입력
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
예제 출력
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