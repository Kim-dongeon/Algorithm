#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int num_palin;
		cin >> num_palin;
		char map[10][10];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				scanf(" %c", &map[i][j]);
			}
		}
		int cnt = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				bool isPalin = true;
				if (j + num_palin <= 8)
				{
					for (int x = 0; x < num_palin / 2; x++)
					{
						if (map[i][x+j] != map[i][num_palin - x-1+j])
						{
							isPalin = false;
							break;
						}						
					}
					if (isPalin)
					{						
						cnt++;
					}
				}
			}
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				bool isPalin = true;
				if (j + num_palin <= 8)
				{
					for (int x = 0; x < num_palin / 2; x++)
					{
						if (map[x+j][i] != map[num_palin - x - 1 + j][i])
						{
							isPalin = false;
							break;
						}
					}
					if (isPalin)
					{						
						cnt++;
					}
				}
			}
		}
		cout <<"#"<<t+1<<' '<< cnt << endl;
	}
}