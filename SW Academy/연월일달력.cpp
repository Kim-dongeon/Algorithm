#include <iostream>
#include <string>
using namespace std;

char c[9];
int main()
{
	int T;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf(" %c", &c[j]);
		}
		int month = (c[4] - '0') * 10 + (c[5] - '0');
		if (month < 1 || month>12)
		{
			printf("#%d -1\n",i+1);
			continue;
		}
		int day = (c[6] - '0') * 10 + (c[7] - '0');
		if (month == 2)
		{
			if (day > 28 || day < 1)
			{
				printf("#%d -1\n",i+1);
				continue;
			}
		}
		if (month==1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day < 1 || day > 31)
			{
				printf("#%d -1\n",i+1);
				continue;
			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day < 1 || day>30)
			{
				printf("#%d -1\n",i+1);
				continue;
			}
		}
		string s = c;
		s.insert(4, "/").insert(7,"/");
		printf("#%d %s\n", i+1,s.c_str());
	}
}