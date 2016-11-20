#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int dir[8][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 }, {-1,-1},{1,1},{-1,1},{1,-1} };
int chk[52][52];
int firo[52][52];
int fArr[3000];
char map[52][52];
int pRow = 0, pCol = 0, kNum = 0;
int nSize = 0, idx = 0;
int low = 0, high = 0;
int minRes = 10000000;


bool bfs() {
	queue<pair<int, int> > que;
	int cnt = 0;
	que.push(make_pair(pRow, pCol));
	chk[pRow][pCol] = 1;

	while (!que.empty()) {
		int nowR = que.front().first;
		int nowC = que.front().second;
		que.pop();

		if (cnt == kNum) {
			return true;
		}
		
		for (int i = 0; i < 8; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];
			
			//범위 넘었을 때
			if (nextR < 0 || nextC < 0 || nextR >= nSize || nextC >= nSize)
				continue;
			//firo[nextR][nextC]가 low이상 high이하가 아니면 continue
			if (firo[nextR][nextC] < fArr[low] || firo[nextR][nextC] > fArr[high])
				continue;
			// . 이고 방문하지 않았으면 간다
			if (map[nextR][nextC] == '.' && chk[nextR][nextC] != 1) {
				que.push(make_pair(nextR, nextC));
				chk[nextR][nextC] = 1;
			}
			//K이고 방문하지 않았으면 cnt++하고 간다
			if (map[nextR][nextC] == 'K' && chk[nextR][nextC] != 1) {
				cnt++;
				que.push(make_pair(nextR, nextC));
				chk[nextR][nextC] = 1;
			}
		}
	}
	return false;
}

int main() {
	cin >> nSize;
	int kpMin = 10000000, kpMax = -10000000;
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			scanf("\n%c", &map[i][j]);
			if (map[i][j] == 'K') kNum++;
		}
	}
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			int t = 0;
			scanf("%d", &t);
			firo[i][j] = fArr[idx++] = t;
		}
	}
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			if (map[i][j] == 'K' || map[i][j] == 'P') {
				if (kpMin > firo[i][j]) kpMin = firo[i][j];
				if (kpMax < firo[i][j]) kpMax = firo[i][j];
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			if (map[i][j] == 'P') {
				pRow = i;
				pCol = j;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	sort(fArr, fArr + idx);
	
	bool res = false;
	for (int i = 0; i < idx; i++) {
		if (fArr[i] == kpMax) {
			high = i;
			break;
		}
	}

	bool tempFlag = false;
	while (!tempFlag) {
		tempFlag = bfs();
		memset(chk, 0, sizeof(chk));
		if (tempFlag){
			minRes = fArr[high] - fArr[low];
			break;
		} 
		high++;
	}

	low++;
	while (high < idx && fArr[low] <= kpMin) {
		res = bfs();
		memset(chk, 0, sizeof(chk));
		if (res) {
			if (fArr[low] <= fArr[high]) {
				int temp = fArr[high] - fArr[low];
				if (minRes > temp) {
					minRes = temp;
				}
			}
			low++;
		}
		else {
			high++;
		}
		
	}

	cout << minRes << endl;
	return 0;
}