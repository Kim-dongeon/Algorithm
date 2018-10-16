#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int temp;
		cin >> temp;

		string dilm;
		cin >> dilm;

		string str;
		cin >> str;		
		string sub;
		int cnt = 0;
		size_t pos = 0;
		while ((pos = str.find(dilm)) != string::npos){
			sub = str.substr(0, pos);
			cnt++;
			str.erase(0, pos + dilm.length());
		}
		cout << "#"<<t+1<<' ' <<cnt << endl;
		
	}
}