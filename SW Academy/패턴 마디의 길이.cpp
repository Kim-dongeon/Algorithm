#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		
		for (int j = 2; j < str.size()/2; j++)
		{
			bool flag = false;
			for (int k = 0; k < j; k++)
			{
				if (str[k] != str[k + j])
				{
					flag = true;
					break;					
				}
			}
			if (!flag )
			{
				printf("#%d %d\n", i + 1, j);
				break;
			}
		}

	}
}