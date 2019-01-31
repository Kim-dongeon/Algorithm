#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool NoPrime[1000001];
int main() {
	NoPrime[0] = true;
	NoPrime[1] = true;

	for (int i = 2; i < sqrt(1000001); i++) {
		for (int j = 2 * i; j < 1000001; j += i) {
			if (!NoPrime[j]) {
				NoPrime[j] = true;
			}
		}
	}
	
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) { break; }
		int len = n / 2;
		for (int i = 2; i <= len; i++) {
			if (!NoPrime[i]) {
				if (!NoPrime[n - i])
				{
					printf("%d = %d + %d\n", n, i, n - i);
					break;
				}
			}
			
		}
		
	}
	

}