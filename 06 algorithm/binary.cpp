#include <stdio.h>

void b(int x) {
	if (x == 0) {
		printf("0");
		return;
	}
	else if (x == 1) {
		printf("1");
		return;
	}

	b(x / 2);
	printf("%d", x % 2);
}
int main() {
	int n;
	scanf("%d", &n);
	b(n);

	return 0;
}