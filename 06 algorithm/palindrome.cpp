#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool pal(char arr[], int start, int end) {
	if (start == end) {
		return true;
	}
	if (start + 1 == end) {
		if (arr[start] == arr[end]) {
			return true;
		}
		else {
			return false;
		}
	}
	if (arr[start] == arr[end]) {
		return pal(arr, start + 1, end - 1);
	}
	else {
		return false;
	}
}
int main() {

	char arr[10] = "abba";

	cout << pal(arr, 0, strlen(arr) - 1);
	
	string s;
	cin >> s;

	for (int i = 0; i<s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
	return 0;
}