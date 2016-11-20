#include <iostream>
#include <algorithm>

using namespace std;

int mSize, cnt;
int dir[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int ans[700];
char map[30][30];

void dfs(int r, int c) {
	map[r][c] = '0';
	ans[cnt - 1] += 1;

	for (int i = 0; i < 4; i++) {
		int nextR = r + dir[i][0];
		int nextC = c + dir[i][1];

		if (nextR < 0 || nextC < 0 || nextR >= mSize || nextC >= mSize)
			continue;
		if (map[nextR][nextC] == '0')
			continue;

		dfs(nextR, nextC);
	}
}
int main() {
	cin >> mSize;
	for (int i = 0; i < mSize; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < mSize; i++) {
		for (int j = 0; j < mSize; j++) {
			if (map[i][j] == '1') {
				cnt++;
				dfs(i, j);
			}
		}
	}
	sort(ans, ans+cnt);
	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}