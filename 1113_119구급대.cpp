#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int row, col;
int map[200][200];
int res[200][200];
int direct[200][200];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }}; //╩С аб го ©Л
int gRow, gCol;
queue<pair<int, int> > que;

void bfs(int r, int c) {
	res[r][c] = 0;
	for (int i = 2; i < 4; i++) {
		int tR = r + dir[i][0];
		int tC = c + dir[i][1];

		if (tR < 0 || tC < 0 || tR >= row || tC >= col)
			continue;
		if (map[tR][tC] == 0)
			continue;

		res[tR][tC] = 0;
		direct[tR][tC] = i;
		que.push(make_pair(tR, tC));
	}

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		int nowStep = res[nowR][nowC];
		int nowD = direct[nowR][nowC];
		que.pop();
		
		if (nowR == gRow && nowC == gCol) {
			cout << res[nowR][nowC] << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];
			int nextStep = nowStep + 1;

			if (nextR < 0 || nextC < 0 || nextR >= row || nextC >= col)
				continue;
			if (map[nextR][nextC] == 0)
				continue;
			if (i != nowD) {
				if (res[nextR][nextC] != -1 && res[nextR][nextC] <= nextStep)
					continue;
				que.push(make_pair(nextR, nextC));
				res[nextR][nextC] = nextStep;
			}
			else {
				if (res[nextR][nextC] != -1 && res[nextR][nextC] <= nowStep)
					continue;
				que.push(make_pair(nextR, nextC));
				res[nextR][nextC] = nowStep;
			}
			direct[nextR][nextC] = i;
		}
	}

}
int main() {
	cin >> col >> row;
	cin >> gRow >> gCol;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	memset(res, -1, sizeof(res));
	bfs(0, 0);

	return 0;
}