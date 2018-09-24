#include <iostream>

using namespace std;

int dx[4] = {0,1,0,-1}; //©Л,го,аб,╩С
int dy[4] = {1,0,-1,0};
int main()
{
	int n;
	cin >> n;
	int arr[26][26];
	int x = 0, y = 0;
	int val = 1;
	int r_edge = n-1;
	int l_edge = 0;
	int direction = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[x][y] = val;
			val++;
			
			if (direction == 0 && y == r_edge)	
			{
				direction = (direction + 1) % 4;
				
			}
			else if (direction == 1 && x == r_edge)	
			{
				direction = (direction + 1) % 4;
				r_edge--;
			}
			else if (direction == 2 && y == l_edge )	
			{
				direction = (direction + 1) % 4;
				l_edge++;
			}
			else if (direction == 3 &&  x == l_edge)	
			{
				direction = (direction + 1) % 4;

			}
			x += dx[direction];
			y += dy[direction];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}