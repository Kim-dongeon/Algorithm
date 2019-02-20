#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	string num1;
	string num2;
	string ans = "";
	cin >> num1 >> num2;

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
			temp = (num1[num1_sz] - '0') + (num2[num2_sz] - '0') + carry;
		}
		if (temp>9) {
			carry = temp / 10;
			temp = temp % 10;
		}
		else {
			carry = 0;
		}
		ans.insert(0, 1, (temp + '0'));

		num1_sz--;
		num2_sz--;
	}
	if (carry != 0) {
		ans.insert(0, 1, (carry + '0'));
	}

	cout << ans;
	return 0;
}