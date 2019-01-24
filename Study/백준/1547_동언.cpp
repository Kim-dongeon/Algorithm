#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ball[] = {0, 1,2,3 };
int main() {
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);		
		swap(ball[find(ball, ball + 4, x)-ball], ball[find(ball, ball + 4, y)-ball]);
	}
	printf("%d", ball[1]);
}