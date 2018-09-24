#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

int map[13][13];
int check[201];
bool visited[13][13];
int N, M;
int dx[2] = {0, 1};
int dy[2] = { 1,0 };
int route_num;
vector<int> route_size;
int route_temp;
void go(int row, int col)
{

	if (visited[row][col] == true)
	{
		return;
	}
	visited[row][col] = true;
	check[map[row][col]] = true;
	route_temp +=map[row][col];
	for (int i = 0; i < 2; i++)
	{
		int nx = dx[i] + row;
		int ny = dy[i] + col;
		if (nx >= 0 && ny >= 0 && nx < N && ny < M && check[map[nx][ny]] == false)
		{
			go(nx, ny);
		}		
	}

	if (row == N-1 && col == M-1)
	{
		route_size.push_back(route_temp);
		route_num++;
	}
	route_temp -= map[row][col];
	visited[row][col] = false;
	check[map[row][col]] = false;
}
int main()
{
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
			}
		}
		go(0, 0);
		int max_route = 0;
		if (route_num > 0)
		{
			sort(route_size.begin(), route_size.end(), greater<int>());

			 max_route= route_size[0];
		}
		if (max_route == 0)
		{
			max_route = -1;
		}
		printf("#%d %d %d\n", t + 1, route_num, max_route);

		route_num = 0;
		route_temp = 0;
		memset(visited, false, sizeof(visited));
		memset(check, false, sizeof(check));
		route_size.erase(route_size.begin(), route_size.end());

	}
}