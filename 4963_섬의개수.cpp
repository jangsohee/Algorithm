#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int map[52][52];

int row, col;
int dir[8][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };
int cnt = 0;

void bfs(int r, int c) {
	queue<pair<int, int> > que;
	que.push(make_pair(r, c));
	map[r][c] = cnt;

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		que.pop();

		for (int i = 0; i < 8; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];

			if (nextR < 0 || nextC < 0 || nextR >= row || nextC >= col)
				continue;

			if (map[nextR][nextC] == -1) {
				map[nextR][nextC] = cnt;
				que.push(make_pair(nextR, nextC));
			}	
		}
	}

}

int main() {
	
	while (1) {
		scanf("%d %d", &col, &row);
		if (row == 0 && col == 0) break;

		memset(map, 0, sizeof(map));
		cnt = 0;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int temp = 0;
				scanf("%d", &temp);
				if (temp == 1) {
					map[i][j] = -1;
				}
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == -1) {
					cnt++;
					bfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}