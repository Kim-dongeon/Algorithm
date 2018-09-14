#include <iostream>

using namespace std;

int bil[8] = { 50000,10000,5000,1000,500,100,50,10 };
int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int money;
		cin >> money;
		int cnt[8] = { 0, };
		for (int i = 0; i < 8; i++)
		{
			cnt[i] = money / bil[i];
			money = money - (cnt[i] * bil[i]);
		}
		printf("#%d\n", t + 1);
		for (int i = 0; i < 8; i++)
		{
			printf("%d ", cnt[i]);
		}
		printf("\n");
	}
}