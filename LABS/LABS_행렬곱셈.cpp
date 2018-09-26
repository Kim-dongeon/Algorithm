#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n1, m1, n2, m2;
	cin >> n1 >> m1 >> n2 >> m2;
	vector < vector<int>> v1;
	vector<vector<int>> v2;

	for (int i = 0; i < n1; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m1; j++)
		{
			int t;
			cin >> t;
			temp.push_back(t);
		}
		v1.push_back(temp);
	}

	for (int i = 0; i < n2; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m2; j++)
		{
			int t;
			cin >> t;
			temp.push_back(t);
		}
		v2.push_back(temp);
	}

	vector<vector<int>> answer;
	for (int i = 0; i < n1; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m2; j++)
		{
			int sum = 0;
			for (int k = 0; k < n2; k++)
			{
				sum += v1[i][k] * v2[k][j];
			}
			temp.push_back(sum);
		}
		answer.push_back(temp);
	}

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << endl;
	}

}