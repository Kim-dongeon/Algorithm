#include <iostream>
#include <cstdio>
using namespace std;

int _min = 9999;
int N, M;
bool arr[52][52];
void chk(bool start, bool chess[][8])
{
	bool flag = start;
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chess[i][j] != flag)
			{
				cnt++;
			}
			if (cnt > _min)
			{
				return;
			}
			flag = !flag;
		}
		flag = !flag;
	}
	if (_min > cnt)
	{
		_min = cnt;
	}
}
int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			char temp;
			scanf(" %1c", &temp);
			if (temp == 'W') {
				arr[i][j] = true;
			}
			else {
				arr[i][j] = false;
			}
		}
	}

	int row = N - 7;
	int col = M - 7;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			bool chess[8][8];
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					chess[x][y] = arr[x + i][y + j];
				}
			}

			bool start = arr[i][j];		
			
			chk(start, chess);			
			chk(!start, chess);
			
		}
	}


	cout << _min;


}