#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;
int map[1000][1000];
int startX, startY;
int size, n;

int check[1000][1000], check_h[1000][1000];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } }; //»ó ÁÂ ÇÏ ¿ì 

bool isGo(int x, int y) {
	if (x < 0 || y < 0 || x >= size || y >= size || map[x][y] == -2)
		return false;
	return true;
}
bool isGo_h(int x, int y) {
	if (x < 0 || y < 0 || x >= size || y >= size || map[x][y] == -2)
		return false;
	return true;
}
void dfs() {
	queue<pair<int, int> > que;
	que.push(make_pair(startX, startY));
	check[startX][startY] = 0;

	while (!que.empty()) {
		pair<int, int> now = que.front();
		int nowX = now.first;
		int nowY = now.second;
		int nowStep = check[nowX][nowY];
		que.pop();

		//»ó-> »óÁÂ  x = -2 // y = -1
		if (isGo(nowX - 2, nowY - 1) && check[nowX - 2][nowY - 1] == -1) {
			check[nowX - 2][nowY - 1] = nowStep + 1;
			que.push(make_pair(nowX - 2, nowY - 1));
		}
		//»ó-> »ó¿ì x = -2 // y = 1
		if (isGo(nowX - 2, nowY + 1) && check[nowX - 2][nowY + 1] == -1) {
			check[nowX - 2][nowY + 1] = nowStep + 1;
			que.push(make_pair(nowX - 2, nowY + 1));
		}
		//ÁÂ-> ÁÂ»ó  x = -1 // y = -2 
		if (isGo(nowX - 1, nowY - 2) && check[nowX - 1][nowY - 2] == -1) {
			check[nowX - 1][nowY - 2] = nowStep + 1;
			que.push(make_pair(nowX - 1, nowY - 2));
		}
		//ÁÂ-> ÁÂÇÏ  x = 1 // y = -2
		if (isGo(nowX + 1, nowY - 2) && check[nowX + 1][nowY - 2] == -1) {
			check[nowX + 1][nowY - 2] = nowStep + 1;
			que.push(make_pair(nowX + 1, nowY - 2));
		}
		//ÇÏ-> ÇÏÁÂ  x = 2 // y =  -1
		if (isGo(nowX + 2, nowY - 1) && check[nowX + 2][nowY - 1] == -1) {
			check[nowX + 2][nowY - 1] = nowStep + 1;
			que.push(make_pair(nowX + 2, nowY - 1));
		}
		//ÇÏ-> ÇÏ¿ì  x = 2 // y =  1
		if (isGo(nowX + 2, nowY + 1) && check[nowX + 2][nowY + 1] == -1) {
			check[nowX + 2][nowY + 1] = nowStep + 1;
			que.push(make_pair(nowX + 2, nowY + 1));
		}
		//¿ì-> ¿ì»ó  x = -1 // y = 2
		if (isGo(nowX - 1, nowY + 2) && check[nowX - 1][nowY + 2] == -1) {
			check[nowX - 1][nowY + 2] = nowStep + 1;
			que.push(make_pair(nowX - 1, nowY + 2));
		}
		//¿ì-> ¿ìÇÏ x =  1 // y = 2
		if (isGo(nowX + 1, nowY + 2) && check[nowX + 1][nowY + 2] == -1) {
			check[nowX + 1][nowY + 2] = nowStep + 1;
			que.push(make_pair(nowX + 1, nowY + 2));
		}
	}
}

void dfs_h() {
	queue<pair<int, int> > que;
	que.push(make_pair(startX, startY));
	check_h[startX][startY] = 0;

	while (!que.empty()) {
		pair<int, int> now = que.front();
		int nowX = now.first;
		int nowY = now.second;
		int nowStep = check_h[nowX][nowY];
		que.pop();

		//»ó-> »óÁÂ  x = -2 // y = -1
		if (map[nowX+dir[0][0]][nowY+dir[0][1]] != -2) {
			if (isGo_h(nowX - 2, nowY - 1) && check_h[nowX - 2][nowY - 1] == -1) {
				check_h[nowX - 2][nowY - 1] = nowStep + 1;
				que.push(make_pair(nowX - 2, nowY - 1));
			}
		}
		//»ó-> »ó¿ì x = -2 // y = 1
		if (map[nowX + dir[0][0]][nowY + dir[0][1]] != -2) {
			if (isGo_h(nowX - 2, nowY + 1) && check_h[nowX - 2][nowY + 1] == -1) {
				check_h[nowX - 2][nowY + 1] = nowStep + 1;
				que.push(make_pair(nowX - 2, nowY + 1));
			}
		}
		//ÁÂ-> ÁÂ»ó  x = -1 // y = -2 
		if (map[nowX + dir[1][0]][nowY + dir[1][1]] != -2) {
			if (isGo_h(nowX - 1, nowY - 2) && check_h[nowX - 1][nowY - 2] == -1) {
				check_h[nowX - 1][nowY - 2] = nowStep + 1;
				que.push(make_pair(nowX - 1, nowY - 2));
			}
		}
		
		//ÁÂ-> ÁÂÇÏ  x = 1 // y = -2
		if (map[nowX + dir[1][0]][nowY + dir[1][1]] != -2) {
			if (isGo_h(nowX + 1, nowY - 2) && check_h[nowX + 1][nowY - 2] == -1) {
				check_h[nowX + 1][nowY - 2] = nowStep + 1;
				que.push(make_pair(nowX + 1, nowY - 2));
			}
		}
		
		//ÇÏ-> ÇÏÁÂ  x = 2 // y =  -1
		if (map[nowX + dir[2][0]][nowY + dir[2][1]] != -2) {
			if (isGo_h(nowX + 2, nowY - 1) && check_h[nowX + 2][nowY - 1] == -1) {
				check_h[nowX + 2][nowY - 1] = nowStep + 1;
				que.push(make_pair(nowX + 2, nowY - 1));
			}
		}
		//ÇÏ-> ÇÏ¿ì  x = 2 // y =  1
		if (map[nowX + dir[2][0]][nowY + dir[2][1]] != -2) {
			if (isGo_h(nowX + 2, nowY + 1) && check_h[nowX + 2][nowY + 1] == -1) {
				check_h[nowX + 2][nowY + 1] = nowStep + 1;
				que.push(make_pair(nowX + 2, nowY + 1));
			}
		}
		//¿ì-> ¿ì»ó  x = -1 // y = 2
		if (map[nowX + dir[3][0]][nowY + dir[3][1]] != -2) {
			if (isGo_h(nowX - 1, nowY + 2) && check_h[nowX - 1][nowY + 2] == -1) {
				check_h[nowX - 1][nowY + 2] = nowStep + 1;
				que.push(make_pair(nowX - 1, nowY + 2));
			}
		}
		
		//¿ì-> ¿ìÇÏ x =  1 // y = 2
		if (map[nowX + dir[3][0]][nowY + dir[3][1]] != -2) {
			if (isGo_h(nowX + 1, nowY + 2) && check_h[nowX + 1][nowY + 2] == -1) {
				check_h[nowX + 1][nowY + 2] = nowStep + 1;
				que.push(make_pair(nowX + 1, nowY + 2));
			}
		}
		
	}
}

int main() {
	scanf("%d %d", &size, &n);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++){
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d", &startX, &startY);
	startX--;
	startY--;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++){
			if (map[i][j] == 1) {
				map[i][j] = - 2;
			}
		}
	}
	memset(check, -1, sizeof(check));
	dfs();
	memset(check_h, -1, sizeof(check_h));
	dfs_h();
	
	//ºñ±³ÇØ¼­ Ãâ·Â
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++){
			if (check[i][j] == -2) {
				continue;
			}
			else if ((check_h[i][j] == -1 && check[i][j] != -1) || (check_h[i][j] == -1 && check[i][j] != -1) || check[i][j] < check_h[i][j]) {
				cnt++; //
			}
		}
	}
	printf("%d\n", cnt);
}