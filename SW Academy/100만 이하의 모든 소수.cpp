#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	bool *noPrime = new bool[1000001];
	memset(noPrime, false, sizeof(bool) * 1000001);
	for (int i = 2; i < sqrt(1000001); i++) {
		
		if (!noPrime[i]) {
			for (int j = i * 2; j < 1000001; j=j+i) {
				noPrime[j] = true;
			}
		}
	}

	for (int i = 2; i < 1000001; i++) {
		if (!noPrime[i]) {
			printf("%d ", i);
		}
	}
}