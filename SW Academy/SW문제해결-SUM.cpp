#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int id;
		cin >> id;
		int arr[101][101];
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> arr[i][j];
			}
		}
		int MAX = 0;
		for (int i = 0; i<100; i++)
		{
			int sum = 0;
			for (int j = 0; j < 100; j++)
			{
				sum += arr[i][j];
			}
			MAX = max(MAX, sum);
		}
		for (int i = 0; i<100; i++)
		{
			int sum = 0;
			for (int j = 0; j < 100; j++)
			{
				sum += arr[j][i];
			}
			MAX = max(MAX, sum);
		}
		int sum = 0;
		for (int i = 0; i < 100; i++)
		{
			sum += arr[i][i];
		}
		MAX = max(MAX, sum);

		sum = 0;
		for (int i = 0; i < 100; i++)
		{
			sum += arr[i][99-i];
		}
		MAX = max(MAX, sum);

		cout << "#" << t + 1 << ' ' << MAX << endl;
	}
}