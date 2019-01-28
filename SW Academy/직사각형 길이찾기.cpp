#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << "#" << t + 1 << " " << (a^b^c) << endl;
	}

}