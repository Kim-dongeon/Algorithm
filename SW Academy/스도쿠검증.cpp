#include <iostream>

using namespace std;

int main()
{
	int T = 0;
	cin >> T;
	
	for (int t = 0; t < T; t++)
	{
		int result = 1;
		int map[9][9] = { 0, };
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 9; i++)
		{
			bool check[10] = { 0, };

			for (int j = 0; j < 9; j++)
			{
				if (check[map[i][j]] == false)
				{
					check[map[i][j]] = true;
				}
				else
				{
					result = 0;
					break;
				}
			}

			if (result == 0)
			{
				break;
			}
		}

		if (result == 1)
		{
			for (int j = 0; j < 9; j++)
			{
				bool check[10]={ 0, };

				for (int i = 0; i < 9; i++)
				{
					if (check[map[i][j]] == false)
					{
						check[map[i][j]] = true;
					}
					else
					{
						result = 0;
						break;
					}
				}

				if (result == 0)
				{
					break;
				}
			}
		}

		if (result == 1)
		{
			for (int i = 0; i < 9; i += 3)
			{				
				for (int j = 0; j < 9; j += 3)
				{
					bool check[10] = { 0, };
					for (int x = 0; x < 3; x++)
					{
						for (int y = 0; y < 3; y++)
						{
							if (check[map[x+i][y+j]] == false)
							{
								check[map[x+i][y+j]] = true;
							}
							else
							{
								result = 0;
								break;
							}
						}
						if (result == 0)
						{
							break;
						}
					}
					if (result == 0)
					{
						break;
					}
				}
				if (result == 0)
				{
					break;
				}
			}
		}

		printf("#%d %d\n", t + 1, result);

	}
}