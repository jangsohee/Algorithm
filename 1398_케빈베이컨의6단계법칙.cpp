#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

int n[102][102];
int chk[102];
int node, edge;
int res = 0;
int minRes = 999999999;
int minIdx = 0;

//cur의 케빈 베이컨 수 리턴
void bfs(int cur) {
	queue<int> que;
	que.push(cur);
	chk[cur] = 0;

	while (!que.empty()) {
		int now = que.front();
		int nowStep = chk[now];
		res += nowStep;
		que.pop();

		for (int i = 1; i <= node; i++) {
			if (n[now][i] == 0) continue;
			if (chk[i] != -1 && chk[i] <= nowStep + 1) continue;

			chk[i] = nowStep + 1;
			que.push(i);
		}
	}
}
int main() {
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int t1 = 0, t2 = 0;
		scanf("%d %d", &t1, &t2);
		n[t1][t2] = n[t2][t1] = 1;
	}
	memset(chk, -1, sizeof(chk));
	for (int i = 1; i <= node; i++) {
		bfs(i);
		if (res < minRes) {
			minIdx = i;
			minRes = res;
		}
		memset(chk, -1, sizeof(chk));
		res = 0;
	}

	cout << minIdx << endl;
	return 0;
}