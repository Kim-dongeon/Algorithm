#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> vec[20010];

int isVisited[20010];
bool answer = true;
void dfs(int node,int color,int V) {
	isVisited[node] = color;
	for (int i = 0; i < vec[node].size(); i++) {
		if (isVisited[vec[node][i]] == isVisited[node] && i!=node) {
			answer = false;
			return;
		}
		if (isVisited[vec[node][i]] == 0 && answer) {
			dfs(vec[node][i], (color%2)+1, V);
		}
	}
}
int main() {
	int K;
	scanf("%d", &K);

	for (int t = 0; t < K; t++) {
		int V, E;
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);			
		}

	

		for (int i = 1; i <= V; i++) {
			if (isVisited[i] == 0) {
				dfs(i, 1, V);
			}
			if (!answer) {
				printf("NO\n");
				break;
			}
		}
		if (answer) {
			printf("YES\n");
		}
	
		answer = true;
		memset(isVisited, 0, sizeof(int)*(V + 1));
		for (int i = 0; i <= V; i++) {
			vec[i].clear();
		}


	}
}