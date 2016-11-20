#include <iostream>
#include <stdio.h>

using namespace std;

char map[21][21] = { 0, };
int path[21][21] = { 0, };
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, {0, 1} }; //╩С, аб, го, ©Л
int n = 0, m = 0;

void doDFS(int xStart, int yStart, int step) {
	
	path[xStart][yStart] = step;
	
	if (xStart == 0 && yStart == (m - 1)) 
		return;
	

	for (int i = 0; i < 4; i++) {
		int x = xStart + dir[i][0];
		int y = yStart + dir[i][1];
		
		if (x < 0 || y < 0 || x >= n || y >= m)
			continue;
		if (map[x][y] == '1')
			continue;
		if (path[x][y] <= step + 1 && path[x][y] != 0)
			continue;

		doDFS(x, y, step + 1);
	}
}
int main() {
	
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
			scanf("%s", &map[i]);
	}

	doDFS(n-1, 0, 1);
	printf("%d\n", path[0][m - 1]);
	return 0;
}
