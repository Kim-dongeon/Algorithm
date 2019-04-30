/*
input
6 11
5 3 18
1 2 21
2 6 25
0 2 31
0 1 32
3 4 34
5 4 40
2 4 46
0 6 51
4 6 51
0 5 60
output
5-3 18
1-2 21
2-6 25
0-2 31
3-4 34
2-4 46
*/
#include <iostream>
#include <algorithm>
using namespace std;

int parent[20];
int Rank[20];

struct edge {
	int v1;
	int v2;
	int cost;
};

edge edges[20];

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
		link(px, py);
	}
}

int main() {
	int V;
	int E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = { a,b,c };
	}

	sort(edges, edges + E, [](edge a, edge b) {
		return a.cost < b.cost;
	});
	
	for (int i = 0; i <= V; i++) {
		make_set(i);
	}

	for (int i = 0; i < E; i++) {
		edge E = edges[i];
		if (find_set(E.v1) != find_set(E.v2)) {
			Union(E.v1, E.v2);
			cout << E.v1 << '-' << E.v2 << ' ' << E.cost << endl;
		}
		
	}
}