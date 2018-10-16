#include <iostream>

using namespace std;

int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int month1, month2, day1, day2;
		cin >> month1 >> day1 >> month2 >> day2;

		int sum = 0;
		if (month1 == month2)
		{
			sum = day2 - day1;
		}
		else
		{
			for (int i = month1 + 1; i < month2; i++)
			{
				sum += day[i];
			}

			sum += day2;
			sum += day[month1] - day1;
		}

		cout << "#" << t + 1 << ' ' << sum+1 << endl;
	}
}