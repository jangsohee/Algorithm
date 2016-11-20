#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int n;
char bang[100][100];
int map[100][100];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
queue<pair<int, int> > que;


void bfs(int x, int y, int cnt) {
	que.push(make_pair(x, y));
	map[x][y] = 0;

	while (!que.empty()) {
		pair<int, int> temp = que.front();
		que.pop();
		int nowX = temp.first;
		int nowY = temp.second;
		int nowStep = map[nowX][nowY];

		if (nowX == n - 1 && nowY == n - 1) return;

		for (int i = 0; i < 4; i++) {
			int next_x = nowX + dir[i][0];
			int next_y = nowY + dir[i][1];

			if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n)
				continue;
			if (map[next_x][next_y] != 0 && map[next_x][next_y] <= nowStep + 1)
				continue;
			//±æÀÌ¾Æ´Ò¶§!
			if (bang[next_x][next_y] == '0') cnt += 1;

			map[next_x][next_y] = cnt;
			que.push(make_pair(next_x, next_y));
		}

	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> bang[i];
	}
	bfs(0, 0, 0);
	cout << map[n-1][n-1] << endl;
	return 0;
}