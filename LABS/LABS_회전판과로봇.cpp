#include <iostream>
#include <deque>
#include <cstdio>
#include <cstring>
using namespace std;

int map[501][501];
int dx[4] = {0,0,1,-1};	//동서남북
int dy[4] = {1,-1,0,0};

void clockwise(deque<int> & deq, int num )
{
	for (int i = 0; i < num; i++)
	{
		int temp = deq.back();
		deq.pop_back();
		deq.push_front(temp);
	}
}
void counterclockwise(deque<int> &deq, int num)
{	
	for (int i = 0; i < num; i++)
	{
		int temp = deq.front();
		deq.pop_front();
		deq.push_back(temp);
	}
}
int main()
{
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, M, X, Y;
		cin >> N >> M >> X >> Y;
		for (int m = 0; m < M; m++)
		{
			for (int n = 0; n < N; n++)
			{
				cin >> map[m][n];
			}
		}
		int K;	//칸의 개수
		cin >> K;
		deque<int> rotate_map;
		for (int k = 0; k < K; k++)
		{
			int temp;
			cin >> temp;
			rotate_map.push_back(temp);
		}
		int L=0;	//움직이는 횟수
		cin >> L;
		
		int last_x = Y-1, last_y = X-1; //마지막 위치
		int sum = map[last_x][last_y]; //점수
		map[last_x][last_y] = 0;
		for (int l = 0; l < L; l++)
		{
			char direction;
			int clock_direc, rotate_num;
			cin >> direction >> clock_direc >> rotate_num;

			if (clock_direc == 1)
			{
				clockwise(rotate_map, rotate_num);
			}
			else
			{
				counterclockwise(rotate_map, rotate_num);
			}
			int go = rotate_map.front(); //실제 움직여야할 수
			int num_direction; //방향을 숫자로 표현
			if (direction == 'N')
			{
				num_direction = 3;
			}
			else if (direction == 'E')
			{
				num_direction = 0;
			}
			else if (direction == 'W')
			{
				num_direction = 1;
			}
			else
			{
				num_direction = 2;
			}

			for (int g = 0; g < go; g++)
			{
				int gx = dx[num_direction] + last_x;
				int gy = dy[num_direction] + last_y;
				//cout << "gx gy : " << gx << " " << gy << endl;
				if (gx >= 0 && gy >= 0 && gx < M && gy < N && map[gx][gy] != -1)
				{
					sum += map[gx][gy];
					last_x = gx;
					last_y= gy;
					map[gx][gy] = 0;
				}
				else
				{
					break;
				}
				//cout << "sum : " << sum << endl;
			}			
		}		
		printf("#%d %d %d %d\n", t + 1, sum, last_y+1, last_x+1);
		//map 초기화
		for (int i = 0; i < 501; i++)
		{
			memset(map, 0, sizeof(int) * 501);
		}
	}
}