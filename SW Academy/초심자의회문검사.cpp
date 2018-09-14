#include <iostream>
#include <string>
using namespace std;

int main()
{
	int  T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string s;
		cin >> s;
		int len = s.length();
		bool flag = false;
		for (int i = 0; i < len/2; i++)
		{
			if (s[i] != s[len - i-1])
			{
				printf("#%d 0\n", t + 1);
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			printf("#%d 1\n", t + 1);
		}
	}
}