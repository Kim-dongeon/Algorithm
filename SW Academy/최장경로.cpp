#include <iostream>
#include <cstring>
using namespace std;

int graph[14][14];
bool isVisted[12];
int MAX_cnt;

void doDFS(int node,int N,int cnt)
{	
	if (cnt > MAX_cnt)
	{
		MAX_cnt = cnt;
	}
	isVisted[node] = true;

	cout << "dddddd " << node << ' ' << cnt << endl;	

	for (int i = 1; i <= N; i++)
	{
		if (isVisted[i] == false && graph[node][i])
		{
			doDFS(i, N, cnt+1);
		}
	}
	cout << "end" << endl;
	isVisted[node] = false;
}
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N >> M;
		
		for (int i = 0; i < M; i++)
		{
			int v1, v2;
			cin >> v1 >> v2;
			graph[v1][v2] = 1;
			graph[v2][v1] = 1;
		}

		for (int i = 1; i <= N; i++)
		{			
			cout << "node start " << i << endl;
			doDFS(i,N,1); 
			memset(isVisted, false, sizeof(isVisted));
		}

		cout << "#" << t + 1 << ' ' << MAX_cnt << endl;
		MAX_cnt = 0;
		memset(isVisted, false, sizeof(isVisted));
		for (int i = 1; i <= N; i++)
		{
			memset(graph[i], 0, sizeof(int)*(N+1));
		}
	}
}