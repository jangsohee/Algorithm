#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int row, col;
int map[102][102];
int temp[102][102];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };

void init(int r, int c) {
	
	if (map[r][c] == 0) {
		map[r][c] = -2;

		for (int i = 0; i < 4; i++) {
			int nR = r + dir[i][0];
			int nC = c + dir[i][1];

			if (nR < 0 || nC < 0 || nR >= row || nC >= col)
				continue;
			init(nR, nC);
		}
	}
}
void copy() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map[i][j] = temp[i][j];
		}
	}
}
bool chk(int r, int c) {
	//int num = 0;

	for (int i = 0; i < 4; i++) {
		int nR = r + dir[i][0];
		int nC = c + dir[i][1];

		if (nR < 0 || nC < 0 || nR >= row || nC >= col)
			continue;
		if (map[nR][nC] == -2) return true;
	}
	//return num;
	return false;
}
int main() {
	scanf("%d %d", &row, &col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%d", &map[i][j]);
			temp[i][j] = map[i][j];
		}
	}
	int hour = 0;
	int cnt = 0;
	while (1) {
		int cntTemp = 0;
		init(0, 0);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 1 && chk(i, j)) {
					temp[i][j] = 0; //-2 ----------------------여기틀림...
					cntTemp++;
				}
			}
		}
		
		if (cntTemp == 0) {
			break;
		}
		else {
			hour++;
			cnt = cntTemp;
			copy();
		}
	}
	
	printf("%d\n", hour);
	printf("%d\n", cnt);
	
	return 0;
}