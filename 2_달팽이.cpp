#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int map[122][122];
int res[122][122];
int nSize, eSize;
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } }; //상좌하우
int maxNum; //maxNum = 1;
 //  -1 초기화, 지나온길 step수, -2 장애물
void dfs(int r, int c, int step, int d) {

	if (res[r][c] == -1) {
		if (maxNum < step - 1) maxNum = step - 1;
		return;
	}

	int nextR = r + dir[d][0];
	int nextC = c + dir[d][1];

	//1.nextRnextC로 검사하지않고 -> r, c로 검사 
	/*if (step > maxNum) maxNum = step;
	if (res[nextR][nextC] != -1 && nextR >= 0 && nextC >= 0 && nextR < nSize && nextC < nSize) {
		if (maxNum < step - 1) maxNum = step - 1;
		return;
	}*/

	//장애물이없고 범위벗어나지않았으면 왔던방향으로
	if (map[nextR][nextC] != -2 && nextR >= 0 && nextC >= 0 && nextR < nSize && nextC < nSize) {
		//res[nextR][nextC] = step + 1;
		res[r][c] = -1;
		dfs(nextR, nextC, step + 1, d);
		res[r][c] = 0;
		//res[nextR][nextC] = -1;

	}
	//왔던방향이 아닌 다른방향으로
	else {
		for (int i = 0; i < 4; i++) {
			if (i == d) continue;
			nextR = r + dir[i][0];
			nextC = c + dir[i][1];

			if (nextR < 0 || nextC < 0 || nextR >= nSize || nextC >= nSize)
				continue;
			if (map[nextR][nextC] == -2)
				continue;
			/*if (res[nextR][nextC] != -1 && res[nextR][nextC] <= step + 1)
				continue;*/

			//res[nextR][nextC] = step + 1;
			//res[nextR][nextC] = -1;
			res[r][c] = -1;
			dfs(nextR, nextC, step + 1, i);
			res[r][c] = 0;
			//res[nextR][nextC] = 0;
			//res[nextR][nextC] = -1;
		} 
	}
	
}

int main() {
	scanf("%d %d", &nSize, &eSize);
	for (int i = 0; i < eSize; i++) {
		char cTemp = NULL;
		int t = 0;
		scanf("\n%c%d", &cTemp, &t);
		map[t - 1][cTemp - 'A'] = -2;
	}
	//memset(res, -1, sizeof(res));
	//res[0][0] = 1;
	dfs(0, 0, 1, 2); 

	//memset(res, -1, sizeof(res));
	//res[0][0] = 1;
	dfs(0, 0, 1, 3);

	cout << maxNum << '\n';
}