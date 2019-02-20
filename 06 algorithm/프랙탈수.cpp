#include <stdio.h>
#include <iostream>

using namespace std;

void fractal(int x) {
	if (x == 1) {
		cout << x << ' ';
		return;
	}

	fractal(x - 1);
	cout << x << ' ';
	fractal(x - 1);
}
int main() {

	int N;
	cin >> N;
	fractal(N);

	return 0;
}