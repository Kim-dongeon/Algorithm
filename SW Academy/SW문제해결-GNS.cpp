#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> num= {"ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN"};
map<string, int> number;
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < 10; i++)
	{
		number.insert(make_pair(num[i], i));
	}
	for (int t = 0; t < T; t++)
	{
		char te;
		int temp;
		cin >> te >> temp;

		int length;
		cin >> length;

		vector<int> arr;
		for (int i = 0; i < length; i++)
		{
			string str;
			cin >> str;
			arr.push_back(number.find(str)->second);
		}

		sort(arr.begin(), arr.end());
		cout << "#" << t + 1 << endl;
		for (int i = 0; i < length; i++)
		{
			for (auto it = number.begin(); it != number.end(); ++it)
			{
				if (it->second == arr[i])
				{
					cout << it->first << ' ';
					break;
				}
			}
		}
	}
}