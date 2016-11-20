#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>

using namespace std;

int map[101][101];
int check[101][101];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int startX, startY, minute;
int size;
queue<pair<int, int> > que;

bool isGo(int x, int y, int no){
	int tempX = x + dir[no][0];
	int tempY = y + dir[no][1];
	if (tempX < 0 || tempY < 0 || tempX >= size || tempY >= size || map[tempX][tempY] == 1) 
		return false;
	else return true;
}

void bfs() {
	que.push(make_pair(startX, startY));
	check[startX][startY] = 0;
	
	while (!que.empty()) {
		pair<int, int> now = que.front();
		que.pop(); 
		int nowX = now.first;
		int nowY = now.second;
		int nowTime = check[nowX][nowY];

		//╩С
		if (isGo(nowX, nowY, 0) && check[nowX-1][nowY] == -1) {
			check[nowX-1][nowY] = nowTime + 1;
			que.push(make_pair(nowX-1, nowY));
		}
		//аб
		if (isGo(nowX, nowY, 1) && check[nowX][nowY - 1] == -1) {
			check[nowX][nowY-1] = nowTime + 1;
			que.push(make_pair(nowX, nowY - 1));
		}
		//го
		if (isGo(nowX, nowY, 2) && check[nowX + 1][nowY] == -1) {
			check[nowX + 1][nowY] = nowTime + 1;
			que.push(make_pair(nowX + 1, nowY));
		}
		//©Л
		if (isGo(nowX, nowY, 3) && check[nowX][nowY +1] == -1) {
			check[nowX][nowY + 1] = nowTime + 1;
			que.push(make_pair(nowX, nowY + 1));
		}
	}
}
int main() {
	memset(check, -1, sizeof(check));
	int cnt = 0;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d %d", &startY, &startX, &minute);
	startX--;
	startY--;

	bfs();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (check[i][j] == minute) cnt++;
		}
	}
	
	if (cnt == 0) {
		printf("OH, MY GOD\n");
	}
	else {
		printf("%d\n", cnt);
	}
	
}