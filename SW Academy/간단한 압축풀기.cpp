#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		char ci;
		int ki;
		int cnt = 0;
		cout << "#" << t + 1 << endl;
		for (int i = 0; i < N; i++)
		{
			cin >> ci >> ki;
			
			for (int i = 0; i < ki; i++)
			{
				cout << ci;
				cnt++;
				if (cnt == 10)
				{
					cout << endl;
					cnt = 0;
				}
			}
		}
		cout << endl;
		
	}
}