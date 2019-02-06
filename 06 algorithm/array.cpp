#include <iostream>
#include <cstring>
using namespace std;

int dx[8] = { 0,0,1,-1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

void multi(int temp[][6], int copy[][6], int mul, int x, int y, int n) {

	copy[x][y] = 1;
	if (mul == 0) {
		return;
	}
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			multi(temp, copy, mul - 1, nx, ny, n);
		}
	}

}
int main() {
	/*
	int arr[][6] = {
	{ 3, 2, 1, 2, 4, 1 },
	{ 2, 1, 2, 1, 2, 1, },
	{ 3, 2, 3, 2, 1, 4 },
	{ 2, 3, 4, 3, 4, 1, },
	{ 3, 4, 3, 4, 3, 4, },
	{ 2, 3, 4, 3, 1, 4 } };

	int n = 6;
	//배열 회전
	int copy[6][6];
	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	copy[i][j] = arr[n - 1 - j][i];
	}
	}

	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	cout << copy[i][j] << ' ';
	}
	cout << endl;
	}
	cout << endl;
	//배열 달팽이
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int direction = 0;
	int right_edge = n - 1;
	int left_edge = 0;
	int x=0, y=0;
	int val = 1;
	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	arr[x][y] = val++;
	//cout << arr[x][y] << ' ';
	x += dx[direction];
	y += dy[direction];
	if (direction == 0 && y == right_edge) {
	direction = (direction + 1) % 4;
	}
	else if (direction == 1 && x == right_edge) {
	direction = (direction + 1) % 4;
	right_edge--;
	}
	else if (direction == 2 && y == left_edge) {
	direction = (direction + 1) % 4;
	left_edge++;
	}
	else if (direction == 3 && x == left_edge) {
	direction = (direction + 1) % 4;
	}
	}
	//cout << endl;
	}
	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	cout << arr[i][j] << ' ';
	}
	cout << endl;
	}
	*/

	//배열 확대
	int temp[][6] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 0, },
		{ 0, 0, 0, 0, 0, 1 } };


	int mul = 2;
	int n = 6;
	int copy[6][6];

	for (int i = 0; i < n; i++) {
		memset(copy[i], 0, sizeof(int)*n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 1) {
				multi(temp, copy, mul, i, j, n);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << copy[i][j] << ' ';
		}
		cout << endl;
	}
}