#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int N[15][15];
int dir[3][2] = { { -1, 0 }, { -1, -1 }, { -1, 1 } };
int res, nSize;

bool chk(int row, int col) {
	for (int i = 0; i < 3; i++) {
		int nowR = row + dir[i][0];
		int nowC = col + dir[i][1];

		while (nowR >= 0 && nowC >= 0 && nowR < nSize && nowC < nSize) {
			if (N[nowR][nowC] == 1) return false;
			nowR += dir[i][0];
			nowC += dir[i][1];
		}
	}
	return true;
}

void proc(int cur) {
	
	if (cur == nSize) {
		res++;
		return;
	}

	for (int i = 0; i < nSize; i++) {
		if (chk(cur, i)) {
			N[cur][i] = 1;
			proc(cur + 1);
			N[cur][i] = 0;
		}
	}
}
int main() {
	int tc = 0;
	scanf("%d", &tc);

	while (tc--) {
		res = 0;
		nSize = 0;
		memset(N, 0, sizeof(int)* 15 * 15);

		scanf("%d", &nSize);

		proc(0);

		printf("%d\n", res);
		
	}
	return 0;
}