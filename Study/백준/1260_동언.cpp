#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

void bfs(int N, int start, int **arr)
{
	queue<int> que;
	que.push(start);

	bool *isVisited = new bool[N] {false, };

	isVisited[start] = true;
	while (!que.empty())
	{
		int n = que.front();
		que.pop();
		cout << n + 1 << ' ';
		for (int i = 0; i < N; i++)
		{
			if (arr[n][i] == 1 && isVisited[i] == false)
			{
				isVisited[i] = true;
				que.push(i);
			}
		}
	}
}
bool dfs_visited[1001];
void dfs(int N, int start, int **arr)
{
	dfs_visited[start] = true;
	cout << start + 1 << ' ';

	for (int i = 0; i < N; i++)
	{
		if (arr[start][i]==1 && dfs_visited[i] == false)
		{
			dfs(N, i, arr);
		}
	}
}
int main()
{
	int N, M,start;
	scanf("%d %d %d", &N, &M, &start);


	int **arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		memset(arr[i], 0, sizeof(int)*N);
	}

	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a-1][b-1] = 1;
		arr[b-1][a-1] = 1;
	}
	
	dfs(N, start - 1, arr);
	cout << endl;
	bfs(N, start - 1, arr);




	delete[] arr;
}