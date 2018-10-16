#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		vector<int> people(100001);
		int N;
		cin >> N;
		int MIN = 200000;
		for (int n = 0; n < N; n++)
		{
			int num;
			cin >> num;
			people[abs(num)]++;
			MIN = min(MIN, abs(num));
		}
		cout << "#"<<t+1<<' ' <<MIN<< ' '<< people[MIN]<<endl;
	}
}