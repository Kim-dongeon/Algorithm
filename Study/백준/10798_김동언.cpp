#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char arr[20][20];
int main() {
	
	int row = 0;
	for (int i = 0; i < 5; i++) {
		string str;
		getline(cin, str);
		
		for (int j = 0; j < str.size(); j++) {
			arr[row][j] = str[j];
		}
		row++;
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != NULL) {
				cout << arr[j][i];
			}
		}
	}


}