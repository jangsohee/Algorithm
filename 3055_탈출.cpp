#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

char map[60][60];
int mapRes[60][60];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
queue<pair<int, int> > que;
int rNum = 0, cNum = 0;
int minRes = -1;

void fire(int nStep) {
	for (int i = 0; i < rNum; i++) {
		for (int j = 0; j < cNum; j++) {
			if (map[i][j] == '*' && mapRes[i][j] == nStep-1) {
				for (int d = 0; d < 4; d++) {
					int nextR = i + dir[d][0];
					int nextC = j + dir[d][1];

					if (nextR < 0 || nextC < 0 || nextR >= rNum || nextC >= cNum)
						continue;
					if (map[nextR][nextC] == 'D' || map[nextR][nextC] == 'X' || map[nextR][nextC] == '*')
						continue;
					
					map[nextR][nextC] = '*';
					mapRes[nextR][nextC] = nStep;
				}
			}
		}
	}
}
void bfs(int row, int col) {
	que.push(make_pair(row, col));
	mapRes[row][col] = 0;

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		int nowStep = mapRes[nowR][nowC];
		que.pop();
	
		if (map[nowR][nowC] == 'D') {
			minRes = nowStep;
			return;
		}
		fire(nowStep);
		for (int i = 0; i < 4; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];

			if (nextR < 0 || nextC < 0 || nextR >= rNum || nextC >= cNum)
				continue;
			if (map[nextR][nextC] == 'X')
				continue;
			if (map[nextR][nextC] == '*')
				continue;
			if (mapRes[nextR][nextC] != -1 && mapRes[nextR][nextC] >= nowStep + 1)
				continue;

			mapRes[nextR][nextC] = nowStep + 1;
			que.push(make_pair(nextR, nextC));
		}
	}

}

int main() {
	cin >> rNum >> cNum;
	for (int i = 0; i < rNum; i++) {
		for (int j = 0; j < cNum; j++) {
			scanf("\n%c", &map[i][j]);
		}
	}
	memset(mapRes, -1, sizeof(mapRes));

	for (int i = 0; i < rNum; i++) {
		bool flag = false;
		for (int j = 0; j < cNum; j++) {
			if (map[i][j] == 'S') {
				bfs(i, j);
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	if (minRes == -1) {
		cout << "KAKTUS" << endl;
	}
	else {
		cout << minRes << endl;
	}
	return 0;
}