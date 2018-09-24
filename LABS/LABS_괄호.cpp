#include <iostream>
#include <string>
using namespace std;

int main()
{	
	//백준 9012번
	string str;
	cin >> str;
	int len = str.size();
	if (str[0] != '(' || str[len - 1] != ')')
	{
		cout << "NO" << endl;		
	}
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			cnt++;
		}
		else
		{
			cnt--;
		}
		if (cnt < 0)
		{
			break;
		}
	}

	if (cnt == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}


//---------------------------stack으로 구현
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<int> st;
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			st.push(1);
		}
		else
		{
			if (st.empty())
			{
				cout << "NO" << endl;
				return 0;
			}
			st.pop();
		}
	}

	if (st.empty())
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}