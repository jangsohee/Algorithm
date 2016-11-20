#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int box[102][102][102];
int res[102][102][102];
int dir[6][3] = { {-1,0,0},{0,-1,0},{1,0,0},{0,1,0},{0,0,1},{0,0,-1} }; //r,c,h 상좌하우 위아래
int row, col, H;

queue<pair<int, pair<int, int> > > que; // h, r, c
void bfs() {
	//익은 토마토들을 모두 큐에 먼저 넣는다
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (box[h][i][j] == 1) {
					que.push(make_pair(h, make_pair(i, j)));
					res[h][i][j] = 0;
				}
			}
		}
	}

	while (!que.empty()) {
		int nowH = que.front().first;
		int nowR = que.front().second.first;
		int nowC = que.front().second.second;
		int nowDay = res[nowH][nowR][nowC];
		que.pop();

		for (int i = 0; i < 6; i++) {
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];
			int nextH = nowH + dir[i][2];

			//범위 넘었을 때 x
			if (nextR < 0 || nextC < 0 || nextH < 0 || nextR >= row || nextC >= col || nextH >= H)
				continue;
			// 빈칸이거나 익은토마토일때 -1, 1 x
			if (box[nextH][nextR][nextC] == -1 || box[nextH][nextR][nextC] == 1)
				continue;
			//최단이 아닐 때 x
			if (res[nextH][nextR][nextC] != -1 && res[nextH][nextR][nextC] <= nowDay + 1)
				continue;

			res[nextH][nextR][nextC] = nowDay + 1;
			que.push(make_pair(nextH, make_pair(nextR, nextC)));
		}
	}
}
int main() {
	cin >> col >> row >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				scanf("%d", &box[h][i][j]);
				res[h][i][j] = -1;
			}
		}
	}
	//모두 익어있는상태인지 아닌지 
	bool allFlag = false;
	for (int h = 0; h < H; h++) {
		bool f1 = false;
		for (int i = 0; i < row; i++) {
			bool f2 = false;
			for (int j = 0; j < col; j++) {
				if (box[h][i][j] == 0) { //익지않은 토마토 발견 
					allFlag = f1 = f2 = true;
					break;
				}
			}
			if (f2) break;
		}
		if (f1) break;
	}
	
	if (allFlag) {
		bfs();
		int maxNum = 0;
		int allSuc = true;
		for (int h = 0; h < H; h++) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					//익지않은 토마토인데 초기화 그대로 일 때 
					if (res[h][i][j] == -1 && box[h][i][j] == 0) {
						allSuc = false;
					}
					else {
						if (res[h][i][j] > maxNum) maxNum = res[h][i][j];
					}
				}
			}
		}
		if (allSuc) {
			cout << maxNum << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}