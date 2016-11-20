#include <iostream>
#include <stdio.h>

using namespace std;

char maze[200][200];
int map[200][200];
int mapRG[200][200];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int n = 0;
int cnt1 = 0, cnt2 = 0;
char rgb[5] = { 'X', 'R', 'G', 'B' };

void doDFS(int x, int y, int num) {
	//rgb 숫자입력
	if (num == -1) {
		for (int i = 0; i < 4; i++) {
			if (maze[x][y] == rgb[i]) {
				num = i;
				break;
			}	
		}
	}
	map[x][y] = num;
	
	for (int i = 0; i < 4; i++) {
		int nowX = x + dir[i][0];
		int nowY = y + dir[i][1];

		if (nowX < 0 || nowY < 0 || nowX >= n || nowY >= n)
			continue;
		if (maze[nowX][nowY] != rgb[num])
			continue;
		if (map[nowX][nowY] != 0)
			continue;

		doDFS(nowX, nowY, num);
	}
}
void doDFS_RG(int x, int y, int num) {
	//rgb 숫자입력
	if (num == -1) {
		for (int i = 0; i < 4; i++) {
			if (maze[x][y] == rgb[i]) {
				num = i;
				break;
			}
		}
	}
	mapRG[x][y] = num;

	for (int i = 0; i < 4; i++) {
		int nowX = x + dir[i][0];
		int nowY = y + dir[i][1];

		if (nowX < 0 || nowY < 0 || nowX >= n || nowY >= n)
			continue;
		/*if (maze[nowX][nowY] == rgb[3] && maze[nowX][nowY] != rgb[num])
			continue;*/
		/*if ((num == 1 || num == 2) && (maze[nowX][nowY] != rgb[1] || maze[nowX][nowY] != rgb[2]))
			continue;*/
		/*if (num == 1 || num == 2 && (maze[nowX][nowY] != rgb[1] && maze[nowX][nowY] != rgb[2]))
			continue;*/
		if (num == 1 && maze[nowX][nowY] != 'R') {
			if (maze[nowX][nowY] != 'G')	continue;
		}
		if (num == 2 && maze[nowX][nowY] != 'R') {
			if (maze[nowX][nowY] != 'G')	continue;
		}
		if (num == 3 && maze[nowX][nowY] != 'B')
			continue;
		/*if (num != 3 && maze[nowX][nowY] == 'B')
			continue;*/
		if (mapRG[nowX][nowY] != 0)
			continue;
		
		
		doDFS_RG(nowX, nowY, num);
	}
}
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}

	//doDFS();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				doDFS(i, j, -1);
				cnt1++;
			}
		}
	}
	//doDFS_RG
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mapRG[i][j] == 0) {
				doDFS_RG(i, j, -1);
				cnt2++;
			}
		}
	}
	printf("%d %d\n", cnt1, cnt2);
	
}
