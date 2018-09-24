#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (i == 0 || i == b - 1)
			{
				printf("*");
			}
			else
			{
				if (j == 0 || j == a - 1)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}