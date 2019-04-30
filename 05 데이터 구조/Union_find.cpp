#include <iostream>

using namespace std;

int parent[10];
int Rank[10];
void print_set() {
	cout << "index  : ";
	for (int i = 0; i < 5; i++) {
		cout << i << ' ';
	}
	cout << endl;
	cout << "parent : ";
	for (int i = 0; i < 5; i++) {
		cout << parent[i] << ' ';
	}
	cout << endl;
	cout << "=========" << endl;
}
void make_set(int x) {
	parent[x] = x;
}

int find_set(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		parent[x] = find_set(parent[x]);
		return parent[x];
	}
}
void link(int px, int py) {
	if (Rank[px] > Rank[py]) {
		parent[py] = px;
	}
	else {
		parent[px] = py;

		if (Rank[px] == Rank[py]) {
			Rank[py]++;
		}
	}
}
void Union(int x, int y) {
	int px = find_set(x);
	int py = find_set(y);

	if (px != py) {
		//parent[py] = px;
		link(px, py);
	}
}
int main() {
	for (int i = 0; i < 5; i++) {
		make_set(i);
	}

	print_set();
	Union(0, 1); print_set();
	Union(1, 4); print_set();
	Union(2, 3); print_set();
}