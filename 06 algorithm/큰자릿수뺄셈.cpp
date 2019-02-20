#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {

	string num1;
	string num2;
	string ans = "";
	cin >> num1 >> num2;

	int flag = false; //정답이 양수
	if (num1.size() < num2.size()) {
		string temp = num1;
		num1 = num2;
		num2 = temp;
		flag = true;
	}
	else if (num1.size() == num2.size()) {
		if (num1 < num2) {
			string temp = num1;
			num1 = num2;
			num2 = temp;
			flag = true;
		}
	}
	int num1_sz = num1.size() - 1;
	int num2_sz = num2.size() - 1;
	int carry = 0;
	while (num1_sz >= 0 || num2_sz >= 0) {
		int temp = 0;

		if (num1_sz < 0 && num2_sz >= 0) {
			temp = (num2[num2_sz] - '0') + carry;
		}
		else if (num1_sz >= 0 && num2_sz < 0) {
			temp = (num1[num1_sz] - '0') + carry;
		}
		else if (num1_sz >= 0 && num2_sz >= 0) {
			temp = (num1[num1_sz] - '0') - (num2[num2_sz] - '0') + carry;
		}
		if (temp<0) {
			temp += 10;
			carry = -1;
		}
		else {
			carry = 0;
		}

		ans.insert(0, 1, (temp + '0'));
		num1_sz--;
		num2_sz--;
	}
	if (ans[0] == '0' && ans.size() != 1) {
		while (ans.size() != 1 && ans[0] == '0') {
			ans = ans.erase(0, 1);
		}
	}
	if (flag) {
		ans = "-" + ans;
	}
	cout << ans;
	return 0;
}