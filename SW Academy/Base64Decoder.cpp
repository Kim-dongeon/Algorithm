#include <iostream>
#include <bitset>
#include <cctype>
#include <string>
#include <map>
using namespace std;

map<char, int> m;
int main()
{
	int idx = 0;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		m[c] = idx;
		idx++;
	}
	for (char c = 'a'; c <= 'z'; c++)
	{
		m[c] = idx;
		idx++;
	}
	for (char c = '0'; c <= '9'; c++)
	{
		m[c] = idx;
		idx++;
	}
	m['+'] = 62;
	m['/'] = 63;
	
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string s;
		cin >> s;
		string str_bit;
		for (int i = 0; i < s.length(); i++)
		{			
			bitset<6> bit;
			bit = m.find(s[i])->second;
			str_bit+=bit.to_string();
		}
		cout << "#" << t + 1 << ' ';
		for (int i = 0; i < str_bit.size(); i += 8)
		{			
			string substr = str_bit.substr(i, 8);
			char answer = stoi(substr,0, 2);
			cout << answer;			
		}	
		cout << endl;
	}
}