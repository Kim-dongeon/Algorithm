#include <iostream>
#include <string>

using namespace std;
int main()
{
	
	string str;
	cin >> str;
	bool answer = true;
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			answer = false;
			break;
		}
	}
	if (answer)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}