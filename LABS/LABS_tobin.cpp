#include <iostream>

using namespace std;

int answer[32];
void comb(int set[], int size, int n, int k, int index)
{
	if (k == 0)
	{
		for (int i = 0; i < size; i++)
		{
			answer[set[i]] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			cout << answer[i];
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			answer[i] = 0;
		}
	}
	else if (n == index)
	{
		return;
	}
	else
	{
		set[size] = index;
		comb(set, size + 1, n, k - 1, index + 1);
		comb(set, size, n, k, index + 1);
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	int arr[32];
	comb(arr, 0, n, k, 0);

	
}