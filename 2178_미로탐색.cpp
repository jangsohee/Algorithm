#include <iostream>
#include <stdio.h>
#include <queue>

char map[200][200];
int res[200][200];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int row, col;

using namespace std;

queue<pair<int, int> > que;


void bfs(int x, int y) {
	que.push(make_pair(x, y));
	res[x][y] = 1;

	while (!que.empty()) {
		int nowX = que.front().first;
		int nowY = que.front().second;
		que.pop();
		int nowStep = res[nowX][nowY];

		if (nowX == row - 1 && nowY == col - 1) return;

		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dir[i][0];
			int nextY = nowY + dir[i][1];

			if (nextX < 0 || nextY < 0 || nextX >= row || nextY >= col)
				continue;
			if (map[nextX][nextY] == '0')
				continue;
			if (res[nextX][nextY] != 0 && res[nextX][nextY] <= nowStep + 1) // = 등호꼭붙여야함!!!!!!!!!!!!!!!!!!!!!!!!! 메모리초과!!!!!!!!!!!!!!!!!!!!!! 같으면갈필요없어!!!!큐에넣을필요없어!!!!!!!!!!!!!!
				continue;

			res[nextX][nextY] = nowStep + 1;
			que.push(make_pair(nextX, nextY));
		}
	}
	return;
}
int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("\n%c", &map[i][j]);
		}
	}

	bfs(0, 0);
	cout << res[row - 1][col - 1] << endl;
}