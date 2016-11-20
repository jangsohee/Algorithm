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
		scanf("%d", &nSize);
		proc(0);
		printf("%d\n", res);
	return 0;
}
//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//int N[15][15];
//int dir[3][2] = { {-1,-1},{-1,0},{-1,1} };
//int qNum;
//int cnt;
//
//bool chk(int r, int c) {
//	for (int i = 0; i < 3; i++) {
//		int nextR = r + dir[i][0];
//		int nextC = c + dir[i][1];
//
//		while (nextR >= 0 && nextC >= 0 && nextR < qNum && nextC < qNum) {
//			if (N[nextR][nextC] == 1) return false;
//			nextR += dir[i][0];
//			nextC += dir[i][1];
//		}
//	}
//	return true;
//}
//void proc(int cur, int step) {
//	if (step == qNum) {
//		cnt++;
//		return;
//	}
//	if (cur >= qNum) return;
//
//	for (int i = 0; i < qNum; i++) {
//		int flag = false;
//		for (int j = 0; j < 3; j++) {
//			int nextR = cur + dir[i][0];
//			int nextC = i + dir[i][1];
//
//			if (nextR < 0 || nextC < 0 || nextR >= qNum || nextC >= qNum)
//				continue;
//			if (N[nextR][nextC] == 1) flag = true;
//		}
//		if (flag) continue;
//		if (chk(cur, i)) {
//			N[cur][i] = 1;
//			proc(cur + 1, step+1);
//			N[cur][i] = 0;
//		}
//	}
//}
//int main() {
//	scanf("%d", &qNum);
//	proc(0, 0);
//
//	cout << cnt << '\n';
//	return 0;
//}