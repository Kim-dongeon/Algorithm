#include <iostream>
#include <vector>
using namespace std;
//1547 °ø
int main() {
	int m;
	vector<int> v;
	int arr[3] = { 1,2,3 };
	scanf_s("%d", &m);//°øÀ» ¹Ù²Û È½¼ö

	int a, b;
	for (int i = 0; i < m; i++) {
		scanf_s("%d %d", &a, &b);
		v.clear();
		for (int j = 0; j < 3; j++) {
			if (arr[j] == a || arr[j] == b) {
				v.push_back(j);
			}
		}

		int tmp = arr[v[0]];
		arr[v[0]] = arr[v[1]];
		arr[v[1]] = tmp;
	}

	printf("%d\n",arr[0]);

	return 0;
}