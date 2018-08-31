#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int j = i;
		bool flag = false;
		if ((j > 299 && j < 400) || (j > 599 && j < 700) || (j > 899 && j < 1000)) { cout << '-'; flag = true; }
		j %= 100;
		if ((j > 29 && j < 40) || (j > 59 && j < 70) || (j > 89 && j < 100)) { cout << '-'; flag = true; }
		j %= 10;
		if (j == 3 || j == 6 || j == 9) { cout << "-"; flag = true; }
		if (!flag) { cout << i; }
		printf(" ");
	}
}