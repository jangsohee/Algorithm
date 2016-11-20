#include <iostream>
//-1:꼬리or시작방향없음, -2: 장애물 
int n, b, max;
char maze[120][120];
int map[120][120];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } }; //상좌하우


void dfs(int x, int y, int step, int d) {
	//종료조건: 꼬리만나면
	if (map[x][y] == -1) {
		if (max < step-1) max = step-1;
		return;
	}

	int xTemp = x + dir[d][0];
	int yTemp = y + dir[d][1];
	
	//1. 범위 넘을 때
	if (xTemp < 0 || yTemp < 0 || yTemp >= n || xTemp >= n || maze[xTemp][yTemp] == '*') {
		for (int i = 0; i < 4; i++) {
			xTemp = x + dir[i][0];
			yTemp = y + dir[i][1];
			//안되는 조건	
			//1. 안됬던 길
			if (i == d)
				continue;
			//2. 범위 넘을 때 
			if (xTemp < 0 || yTemp < 0 || yTemp >= n || xTemp >= n)
				continue;
			//3. 장애물 만났을 때
			if (maze[xTemp][yTemp] == '*')
				continue;
			
			//dfs 고
			map[x][y] = -1;
			dfs(xTemp, yTemp, step + 1, i);
			map[x][y] = 0;
		}
	}
	else {
		//왔던 방향으로 쭉 고
		map[x][y] = -1;
		dfs(xTemp, yTemp, step + 1, d);
		map[x][y] = 0;
	}
	
}
int main() {
	scanf("%d %d", &n, &b);
	for (int i = 0; i < b; i++) {
		char alpha = NULL;
		int no = 0;
		scanf("\n%c%d", &alpha, &no);
		maze[no - 1][alpha - 'A'] = '*';
	}
	
	dfs(0, 0, 1, 3); //오른쪽
	dfs(0, 0, 1, 2); //아래쪽
	printf("%d\n", max);
	return 0;
}