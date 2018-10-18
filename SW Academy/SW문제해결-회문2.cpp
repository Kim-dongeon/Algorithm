#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int temp;
		cin >> temp;

		char arr[102][102];
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> arr[i][j];
			}
		}
		
		int max_palin = 0;
	
		for (int i=0;i<100;i++)
		{
			for (int m = 100; m > max_palin; m--)
			{
				bool row_max = false;
				for (int j = 0; j < 100; j++)
				{
					bool isPossible = true;
					if (j + m <= 100)
					{						
						for (int x = 0; x < m / 2; x++)
						{
							if (arr[i][j + x] != arr[i][m - 1 + j - x])
							{
								isPossible = false;
								break;
							}
						}						
					}
					else
					{						
						break;
					}
					if (isPossible)
					{						
						row_max = true;
						break;
					}
				}
				if (row_max)
				{
					max_palin = max(max_palin, m);
					break;
				}
			}
		}

		for (int i = 0; i<100; i++)
		{
			for (int m = 100; m > max_palin; m--)
			{
				bool row_max = false;
				for (int j = 0; j < 100; j++)
				{
					bool isPossible = true;
					if (j + m <= 100)
					{
						for (int x = 0; x < m / 2; x++)
						{
							if (arr[j+x][i] != arr[m-1+j-x][i])
							{
								isPossible = false;
								break;
							}
						}
					}
					else
					{
						break;
					}
					if (isPossible)
					{
						row_max = true;
						break;
					}
				}
				if (row_max)
				{
					max_palin = max(max_palin, m);
					break;
				}
			}
		}
		cout << "#" << t + 1 << ' ' << max_palin << endl;
	}
}