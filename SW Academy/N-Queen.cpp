#include <iostream>
#include <cstring>
using namespace std;

int chess[10][10];
int cnt;

bool check(int row, int col,int N)
{	
	for (int i = 0; i < row; i++)
	{
		if (chess[i][col])
		{
			return false;
		}
	}

	int _row=row-1, _col = col-1;
	while (_row >= 0 && _col >= 0 && _row < N && _col < N)
	{
		if (chess[_row][_col])
		{
			return false;
		}
		_row--;
		_col--;
	}
	_row = row - 1; _col = col + 1;
	while (_row >= 0 && _col >= 0 && _row < N && _col < N)
	{
		if (chess[_row][_col])
		{
			return false;
		}
		_row--;
		_col++;
	}

	return true;
}
void go(int row,int N)
{
	if (row == N)
	{		
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		chess[row][i] = 1;
		if (check(row, i,N))
		{
			go(row + 1, N);
		}
		chess[row][i] = 0;
	}
}
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		go(0, N);
		cout << "#" << t + 1 << ' ' << cnt << endl;
		cnt = 0;
		
		for (int i = 0; i < N; i++)
		{
			memset(chess[i], 0, sizeof(int)*N);
		}
	}
}