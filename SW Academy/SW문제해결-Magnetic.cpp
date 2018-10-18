#include <iostream>
#include <vector>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int table[103][103];
		int temp;
		cin >> temp;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> table[i][j];
			}
		}

		int cnt = 0;
		for (int col = 0; col < 100; col++)
		{
			vector<int> check;
			for (int row = 0; row < 100; row++)
			{
				if (table[row][col] != 0)
				{
					check.push_back(table[row][col]);
				}
			}
			for (int i = 0; i < check.size()-1; i++)
			{
				if (check[i] == 1 && check[i + 1] == 2)
				{
					cnt++;
				}
			}
		}
		cout << "#" << t + 1 << ' ' << cnt << endl;
	}
	
}