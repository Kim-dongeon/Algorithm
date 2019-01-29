#include <iostream>
#include <cstdio>


using namespace std;
int arr[1002][1002];
bool isVisited[1002];
int cnt;
void dfs(int cur_node,int N) {
	isVisited[cur_node] = true;

	for (int i = 1; i <= N; i++) {
		if (arr[cur_node][i] == 1 && isVisited[i] == false) {
			dfs(i, N);
		}
	}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (isVisited[i] == false) {
			dfs(i,N);			
			cnt++;
		}
	}

	printf("%d", cnt);
}