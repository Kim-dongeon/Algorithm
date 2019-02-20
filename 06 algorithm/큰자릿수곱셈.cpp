#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	string num1;
	string num2;
	cin >> num1 >> num2;
	string ans = "";

	int num1_sz = num1.size() - 1;
	int num2_sz = num2.size() - 1;
	int maxsz = -1;
	vector<string> cal_str;
	for (int i = num2_sz; i >= 0; i--) {
		int carry = 0;
		string tmp_str = "";
		for (int k = 0; k<num2_sz - i; k++) {
			tmp_str += "0";
		}
		for (int j = num1_sz; j >= 0; j--) {
			int temp = (num1[j] - '0') * (num2[i] - '0') + carry;

			if (temp>9) {
				carry = temp / 10;
				temp = temp % 10;
			}
			else {
				carry = 0;
			}
			tmp_str.insert(0, 1, temp + '0');
		}
		if (carry) {
			tmp_str.insert(0, 1, carry + '0');
		}
		cal_str.push_back(tmp_str);
		maxsz = (maxsz, tmp_str.size());

	}

	for (string &x : cal_str) {
		if (x.size() < maxsz) {
			while (x.size() < maxsz) {
				x.insert(0, "0");
			}
		}
	}
	int carry = 0;
	for (int i = maxsz - 1; i >= 0; i--) {
		int temp = 0;
		for (int j = 0; j<cal_str.size(); j++) {
			temp += (cal_str[j][i] - '0');
		}
		temp += carry;
		if (temp>9) {
			carry = temp / 10;
			temp = temp % 10;
		}
		else {
			carry = 0;
		}
		ans.insert(0, 1, (temp + '0'));
	}

	if (carry != 0) {
		ans.insert(0, 1, (carry + '0'));
	}

	cout << ans;
	return 0;
}