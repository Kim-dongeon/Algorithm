#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string s;
	map <char, int> m;
	cin >> s;
	for (int i = 1; i <= 26; i++)
	{
		m[i + 64] = i;
	}
	for(int i=0;i<s.size();i++)
	{
		printf("%d ", m[s[i]]);
	}

}