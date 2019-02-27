/*
12 18
1 2
2 3
2 4
3 1
3 7
3 9
4 6
4 11
5 4
6 5
7 8
7 9
8 10
8 12
9 10
10 7
11 12
12 11
답 : 4*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100;

vector<int> List[MAX];
vector<int> reverseList[MAX];
int n, m;

int Time[MAX];
int order[MAX], order_len = 0;
int Clock = -1;
bool check[MAX];
bool check2[MAX];
int group[MAX];
int group_cnt;

void get_time(int node) {
	check[node] = true;

	for (int i = 0; i<List[node].size(); i++) {
		int node2 = List[node][i];

		if (!check[node2]) {
			get_time(node2);
		}
	}

	Time[node] = Clock;
	Clock++;
	order[order_len++] = node;
}
void get_my_group(int node) {
	check2[node] = true;
	group[node] = group_cnt;
	for (int i = 0; i<reverseList[node].size(); i++) {
		int node2 = reverseList[node][i];

		if (!check2[node2]) {
			get_my_group(node2);
		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i<m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		List[a].push_back(b);
		reverseList[b].push_back(a);

	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			get_time(i);
		}
	}
	//빠져나오는 순서대로 시간이 기록됨
	//뒤집은 그래프에 대해서, 빠져나오는 시간이 큰 노드부터 순회
	//이 때 만나는 노드들이 모두 같은 그룹임

	for (int i = order_len - 1; i >= 0; i--) {
		int node = order[i];

		if (!check2[node]) {
			get_my_group(node);
			group_cnt++;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d : %d\n", i, group[i]);
	}
	printf("%d\n", group_cnt);
	return 0;
}