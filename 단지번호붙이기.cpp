#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int wid = 0;
int map[25][25] = {0, };
int danji[900] = {0, };
int danjiNum = 0;
int allStep = 0;

int dir[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };


int compare(const void* a, const void* b) {
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}
void doDFS(int row, int col) {

	allStep++;
	map[row][col] = 0;

	for (int i = 0; i < 4; i++) {
		int nextRow = row + dir[i][0];
		int nextCol = col + dir[i][1];

		if (nextRow < 0 || nextRow >= wid || nextCol < 0 || nextCol >= wid)
			continue;
		if (map[nextRow][nextCol] == 0)
			continue;

		doDFS(nextRow, nextCol);
	}
}
int main() {

	scanf("%d", &wid);

	for (int i = 0; i < wid; i++) {
		for (int j = 0; j < wid; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	
	for (int i = 0; i < wid; i++) {
		for (int j = 0; j < wid; j++) {
			if (map[i][j] == 1) {
				doDFS(i, j);
				danji[danjiNum] = allStep;
				danjiNum++;
				allStep = 0;
			}
		}
	}

	
	printf("%d\n", danjiNum);
	qsort(danji, danjiNum, sizeof(danji[0]), compare);

	for (int i = 0; i < danjiNum; i++) {
		printf("%d\n", danji[i]);
	}
 	return 0;
}