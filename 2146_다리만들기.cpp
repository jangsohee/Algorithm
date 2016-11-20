#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

int map[102][102];
int minNum = 10002;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int N;

void fill(int row, int col, int num) {
	queue<pair<int, int> > que;
	que.push(make_pair(row, col));
	map[row][col] = num; 

	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		//map[r][c] = num; 
		que.pop();

		for (int i = 0; i < 4; i++) {
			int nR = r + dir[i][0];
			int nC = c + dir[i][1];

			if (nR < 0 || nC < 0 || nR >= N || nC >= N)
				continue;

			if (map[nR][nC] == 0 || map[nR][nC] == num)
				continue;

			map[nR][nC] = num; //큐에 담기전에 값을 셋팅해주지 않으면 중복좌표를 큐에 담게된다
			que.push(make_pair(nR, nC));
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				cnt--;
				fill(i, j, cnt);
			}
		}
	}
	if (cnt == 0) {
		cout << 0 << '\n';
		return 0;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] < 0) {
				int sumNum = map[i][j];
				for (int i2 = 0; i2 < N; i2++) {
					for (int j2 = 0; j2 < N; j2++) {
						if (map[i2][j2] != sumNum && map[i2][j2] < 0) {
							int temp = abs(i2 - i) + abs(j2 - j) - 1;
							if (temp < minNum) minNum = temp;
						}
					}
				}
			}
		}
	}
	if (minNum == 10002) {
		cout << 0 << '\n';
		return 0;
	}
	cout << minNum << '\n';
	return 0;
}