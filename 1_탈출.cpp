#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int row, col;
int res[52][52];
int fArr[52][52];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
char map[52][52];
int ans = -1;

void fire() {
	queue<pair<int, int> > que;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == '*') {
				que.push(make_pair(i, j));
				fArr[i][j] = 0;
			}
		}
	}

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		int nowStep = fArr[nowR][nowC];
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];
			int nextStep = nowStep + 1;

			if (nextR < 0 || nextC < 0 || nextR >= row || nextC >= col)
				continue;
			if (map[nextR][nextC] == 'X' || map[nextR][nextC] == 'D')
				continue;
			if (fArr[nextR][nextC] != -1 && fArr[nextR][nextC] <= nextStep)
				continue;

			fArr[nextR][nextC] = nextStep;
			que.push(make_pair(nextR, nextC));
		}
	}
	

}
void bfs(int startR, int startC) {
	queue<pair<int, int> > que;
	que.push(make_pair(startR, startC));
	res[startR][startC] = 0;

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		int nowStep = res[nowR][nowC];
		que.pop();

		if (map[nowR][nowC] == 'D') {
			ans = nowStep;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];
			int nextStep = nowStep + 1;

			if (nextR < 0 || nextC < 0 || nextR >= row || nextC >= col)
				continue;
			if (map[nextR][nextC] == 'X')
				continue;
			if (fArr[nextR][nextC] != -1 && fArr[nextR][nextC] <= nextStep)
				continue;
			if (res[nextR][nextC] != -1 && res[nextR][nextC] <= nextStep)
				continue;

			res[nextR][nextC] = nextStep;
			que.push(make_pair(nextR, nextC));
		}
	}
}

int main() {
	scanf("%d %d", &row, &col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("\n%c", &map[i][j]);
		}
	}
	memset(fArr, -1, sizeof(fArr));
	memset(res, -1, sizeof(res));
	bool flag = false;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 'S') {
				fire();
				bfs(i, j);
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (ans == -1) {
		cout << "KAKTUS" << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}

