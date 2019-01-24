#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;

	string dial = "22233344455566677778889999";
	int ans = 0;

	for (int i = 0; i < str.size(); i++) {		
		ans += (dial[str[i] - 'A'] - '0'+1);
	}
	cout << ans;

	return 0;
}