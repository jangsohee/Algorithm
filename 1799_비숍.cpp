#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int mSize = 0;
int map[11][11];
int dir[4][2] = { { -1, 1 }, { 1, -1 }, { -1, -1 }, { 1, 1 } };
int res;

int bCount() {
	int bCnt = 0;

	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < mSize; j++) {
			if (map[i][j] == -1) bCnt++;
		}
	}
	return bCnt;
}
bool chk(int x, int y) {

	for (int i = 2; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		while (nx >= 0 && ny >= 0 && nx < mSize && ny < mSize) {
			if (map[nx][ny] == -1) return false;
			nx += dir[i][0];
			ny += dir[i][1];
		}
	}
	return true;
}
void bishop(int r, int c) {
	if (r == mSize || c == mSize) {
		int temp = bCount();
		if (temp > res) res = temp;
		return;
	}

	if (map[r][c] == 1 && chk(r, c)) {
		map[r][c] = -1;
		bishop(r + 1, c + 1);
		map[r][c] = 1;
	}
	else {
		bishop(r + 1, c + 1);
	}

	for (int i = 0; i < 2; i++) {
		int croR = r + dir[i][0];
		int croC = c + dir[i][1];

		while (croR >= 0 && croC >= 0 && croR < mSize && croC < mSize) {
			if (map[croR][croC] == 1 && chk(croR, croC)) {
				map[croR][croC] = -1;
				bishop(r + 1, c + 1); 
				map[croR][croC] = 1;
			}
			croR += dir[i][0];
			croC += dir[i][1];
		}
	}
}

int main() {

	cin >> mSize;

	for (int i = 0; i < mSize; i++) {

		for (int j = 0; j < mSize; j++) {

			scanf("%d", &map[i][j]);

		}

	}
	int temp = 0;
	
	bishop(0, 0);
	temp = res;
	res = 0;
	bishop(0, 1);
	temp += res;

	cout << temp << endl;

	return 0;

}