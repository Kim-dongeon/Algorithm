#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int num;
		cin >> num;
		vector<int> box(100);
		for (int i = 0; i < 100; i++)
		{
			cin >> box[i];
		}
		for (int i = 0; i < num; i++)
		{
			sort(box.begin(), box.end());
			box[99]--;
			box[0]++;
		}
		sort(box.begin(), box.end());
		cout << "#" << t + 1 << ' ' << box[99] - box[0] << endl;
	}
}