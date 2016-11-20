#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
int flag = false;
queue<pair<int, int> > que;
int box[1024][1024];
int res[1024][1024];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int r, c;
void bfs() {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (box[i][j] == 1) {
				que.push(make_pair(i, j));
				res[i][j] = 0;
				flag = true;
			}
		}
	}

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		int nowStep = res[nowR][nowC];
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];

			if (nextR < 0 || nextC < 0 || nextR >= r || nextC >= c)
				continue;
			if (box[nextR][nextC] == 1 || box[nextR][nextC] == -1)
				continue;
			if (res[nextR][nextC] != -2 && res[nextR][nextC] <= nowStep + 1)
				continue;

			res[nextR][nextC] = nowStep + 1;
			que.push(make_pair(nextR, nextC));
		}
	}
}
int main() {
	cin >> c >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &box[i][j]);
			res[i][j] = -2;
		}
	}
	bfs();
	bool flag2 = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (box[i][j] != -1 && res[i][j] == -2) {
				flag = false;
				flag2 = true;
				break;
			}
		}
		if (flag2) break;
	}

	if (flag) {
		int resNum = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (res[i][j] > resNum) resNum = res[i][j];
			}
		}
		cout << resNum << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}