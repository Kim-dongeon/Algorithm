#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

//string tree[210];
vector<string> tree(210);
int ans = 1;

void traversal(int node, int N) {

	if (ans == 0) {
		return;
	}

	if (node > N) {
		return;
	}

	traversal(node * 2, N);
	traversal(node * 2 + 1, N);

	if (node * 2 <= N) {
		if (node * 2 + 1 > N) {
			ans = 0;
			return;
		}
	}

	if (node * 2 > N && node * 2 + 1 > N) {

		//숫자만가능
		if ((tree[node].compare("+") == 0 || tree[node].compare("/") == 0 || tree[node].compare("*") == 0 || tree[node].compare("-") == 0)) {
			ans = 0;
		}

	}
	else {
		//문자만 가능
		if (!(tree[node].compare("+") == 0 || tree[node].compare("/") == 0 || tree[node].compare("*") == 0 || tree[node].compare("-") == 0)) {
			ans = 0;
		}
	}
}
int main() {

	for (int t = 0; t < 10; t++) {
		int N;
		scanf("%d", &N);
		cin.ignore();
		for (int i = 0; i < N; i++) {
			string str;

			getline(cin, str);


			stringstream ss(str);
			vector<string> v;

			string sub;
			while (ss >> sub) {

				v.push_back(sub);
			}


			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << ' ';
			}
			cout << endl;

			
			tree[stoi(v[0])] = v[1];
			for (int i = 0; i <= N; i++) {
				cout << tree[i] << ' ';
			}
			cout << endl;

		}

		cout << "=========" << endl;
		for (int i = 0; i <= N; i++) {
			cout << tree[i] << ' ';
		}
		cout << endl;


		traversal(1, N);
		cout << "#" << (t + 1) << ' ' << ans << endl;
		//memset(tree, NULL, sizeof(tree));
		tree.clear();
		tree.resize(210);
		//cout << tree.size();
		ans = 1;
	}

}