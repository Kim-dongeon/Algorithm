#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < arr.size(); i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(arr.begin(), arr.end());
		printf("#%d ", t + 1);
		for (auto it = arr.begin(); it != arr.end(); ++it)
		{
			printf("%d ", *it);
		}
		printf("\n");
	}
}