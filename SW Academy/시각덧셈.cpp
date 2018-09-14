#include <iostream>

using namespace std;

int main()
{
	int T = 0;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int h1, h2, m1, m2;
		cin >> h1 >> m1 >> h2 >> m2;
		int min = (m1 + m2) % 60;
		int hour_plus = (m1 + m2) / 60;
		int hour = h1 + h2 + hour_plus;
	
		if (hour != 12 && hour!=24) hour = hour %12;
		else hour = 12;
		printf("#%d %d %d\n", t + 1, hour, min);
	}
}