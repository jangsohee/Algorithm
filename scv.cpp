#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cache[102][102];
int map[102][102];
int n;

int path(int row, int col) {

	if (row < 0 || col < 0 || row >= n || col >= n) return 0;

	if (row == n - 1 && col == n - 1) return map[n-1][n-1];

	int& ret = cache[row][col];
	if (ret != -1) return ret;

	return ret = max(map[row][col] + path(row + 1, col), map[row][col] + path(row, col + 1));
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cache[i][j] = -1;
		}
	}
	cout << path(0, 0) << endl;

	return 0;
}