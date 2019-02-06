#include <iostream>

using namespace std;

int power(int base, int ex) {
	if (ex == 0) {
		return 1;
	}
	if (ex == 1) {
		return base;
	}
	int n = power(base, ex / 2);
	if (ex % 2 == 0) {
		return n*n;
	}
	else {
		return n*n*base;
	}
}

int main()
{
	power(2, 10);
}