#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int arr[10];
		int _max = -1;
		int _min = 10001;
		float sum = 0;
		for (int i = 0; i < 10; i++)
		{
			scanf("%d", &arr[i]);
			if (_max < arr[i])
			{
				_max = arr[i];
			}
			if (_min > arr[i])
			{
				_min = arr[i];
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] != _min && arr[i] != _max)
			{
				
				sum += arr[i];
			}
		}	
		printf("#%d %.f\n",t+1, floor(sum / 8 + 0.5));

	}
}