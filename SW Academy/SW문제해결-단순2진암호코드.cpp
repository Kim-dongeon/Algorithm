#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int>> v(N, vector<int> (M));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%1d", &v[i][j]);
			}
		}
		
		vector<int> or_code(M);

		for (int i = 0; i < M; i++)
		{
			int temp=0;
			for (int j = 0; j < N; j++)
			{
				temp = temp | v[j][i];
			}
			or_code[i] = temp;
		}
		
		vector<int> code;
		bool flag = false;
		int idx = 0;
		int code_temp = 0;
		for (int i =or_code.size()-1; i>=0; i--)
		{			
			if (or_code[i] == 1)
			{				
				flag = true;
			}
			if (flag == true)
			{
				code_temp += or_code[i] * pow(2, idx);				
				idx++;
			}
			if (idx == 7)
			{
				code.push_back(code_temp);
				idx = 0;
				code_temp = 0;
			}
			if (code.size() == 8)
			{
				break;
			}
		}
		
		for (int i = 0; i < code.size(); i++)
		{
			if (code[i] == 13)
			{
				code[i] = 0;
			}
			else if (code[i] == 25)
			{
				code[i] = 1;
			}
			else if (code[i] == 19)
			{
				code[i] = 2;
			}
			else if (code[i] == 61)
			{
				code[i] = 3;
			}
			else if (code[i] == 35)
			{
				code[i] = 4;
			}
			else if (code[i] == 49)
			{
				code[i] = 5;
			}
			else if (code[i] == 47)
			{
				code[i] = 6;
			}
			else if (code[i] == 59)
			{
				code[i] = 7;
			}
			else if (code[i] == 55)
			{
				code[i] = 8;
			}
			else
			{
				code[i] = 9;
			}
		}
		int sum = 0;
		for (int i = 1; i < 8; i++)
		{			
			if (i % 2 == 0)
			{
				sum += code[i];
			}
			else {				
				sum += (code[i] * 3);
			}
		}
		sum += code[0];
		
		int ans = 0;
		if (sum % 10 == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				ans += code[i];
			}
		}
		cout << "#" << t + 1 << ' ' << ans << endl;
	}
}