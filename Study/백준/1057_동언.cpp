#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int main() {
	int N, J, H;
	scanf("%d %d %d", &N,&J,&H);
	
	for (int i = 0; i < N; i++) {
		if (i == (J-1) || i == (H-1)) {
			v.push_back(1);
		}
		else {
			v.push_back(0);
		}	
	}
	
	int round = 1;

	int len = v.size();
	
	while (true) {
		if (len % 2 == 1) {
			len++;
		}
		len /= 2;
		for (int i = 0; i <len; i++) {
			if ((i + 1) < v.size()) {
				v[i] = v[i] + v[i + 1];
				if (v[i] == 2) {
					printf("%d", round);
					return 0;
				}
				else {
					v.erase(v.begin() + 1 + i);
				}
			}
			else {
				break;
			}
			
		}
		round++;	
	}

	



}