#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char map[52][52];
int res[52][52];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int row, col;

int count() {
	int maxN = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (res[i][j] > maxN) maxN = res[i][j];
		}
	}
	return maxN;
}
void bfs(int r, int c) {
	queue<pair<int, int> > que;
	que.push(make_pair(r, c));
	res[r][c] = 0;

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		int nowStep = res[nowR][nowC];
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];
			int nextStep = nowStep + 1;

			if (nextR < 0 || nextC < 0 || nextR >= row || nextC >= col)
				continue;
			if (map[nextR][nextC] == 'W')
				continue;
			if (res[nextR][nextC] != -1 && res[nextR][nextC] <= nextStep)
				continue;

			que.push(make_pair(nextR, nextC));
			res[nextR][nextC] = nextStep;
		}
	}
}
int main() {
	int ans = 0;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("\n%c", &map[i][j]);
		}
	}
	memset(res, -1, sizeof(res));
	//육지에서 시작
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
				int temp = count();
				if (temp > ans) ans = temp;
				memset(res, -1, sizeof(res));
			}
		}
	}

	cout << ans << endl;
}