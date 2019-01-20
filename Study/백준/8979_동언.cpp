#include<iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct country {
	int num;
	int gold;
	int silver;
	int bronze;
	int rank=1;
};
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	country arr[1002];
	for (int i = 0; i < N; i++) {
		int num = 0, gold = 0, silver = 0, bronze = 0;		
		scanf("%d %d %d %d",&arr[i].num, &arr[i].gold, &arr[i].silver, &arr[i].bronze);
	}

	sort(arr, arr + N, [](country &c1, country &c2) {
		if (c1.gold > c2.gold) {
			return true;
		}
		else if (c1.gold == c2.gold) {
			if (c1.silver > c2.silver) {
				return true;
			}
			else if (c1.silver == c2.silver) {
				return (c1.bronze > c2.bronze);					
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	});


	int cnt = 1;
	int grade = 0;
	
	for (int i = 1; i < N; i++) {
		if (arr[i - 1].gold == arr[i].gold &&arr[i - 1].silver == arr[i].silver&&arr[i - 1].bronze == arr[i].bronze) {
			cnt++;
			arr[i].rank = arr[i-1].rank;
		}
		else{
			arr[i].rank = (arr[i-1].rank + cnt);
			cnt = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		if (K == arr[i].num) {
			printf("%d\n", arr[i].rank);
			break;
		}
	}
}