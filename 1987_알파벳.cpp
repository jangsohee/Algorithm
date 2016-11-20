#include <iostream>

using namespace std;

char map[22][22];
int en[26];
int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int R, C;
int ans = 0;

void dfs(int nowR, int nowC, int step) {
	if (step > ans) ans = step;

	for (int i = 0; i < 4; i++) {
		int nR = nowR + dir[i][0];
		int nC = nowC + dir[i][1];

		if (nR < 0 || nC < 0 || nR >= R || nC >= C)
			continue;
		if (en[map[nR][nC] - 'A'] == 1)
			continue;

		en[map[nR][nC] - 'A'] = 1;
		dfs(nR, nC, step+1);
		en[map[nR][nC] - 'A'] = 0;
	}
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}
	en[map[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << ans << '\n';
	return 0;
}