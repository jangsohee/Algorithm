#include <iostream>
#include <cstdio>

using namespace std;
int nNum, eNum;
int n[1002][1002];
int visit[1002];

void dfs(int cur) {
	visit[cur] = 1;
	for (int i = 1; i <= nNum; i++) {
		if (n[cur][i] == 1 && visit[i] != 1) {
			dfs(i);
		}
	}
}
int main() {
	cin >> nNum >> eNum;
	for (int i = 0; i < eNum; i++) {
		int t1 = 0, t2 = 0;
		scanf("%d %d", &t1, &t2);
		n[t1][t2] = n[t2][t1] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= nNum; i++) {
		if (visit[i] == 0) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt << '\n';
}