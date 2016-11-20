#include <iostream>
#include <cstdio>
using namespace std;

int n[102][102];
int chk[102];
int nNum, eNum;
int cnt = 0;
void dfs(int cur) {
	chk[cur] = 1;

	for (int i = 1; i <= nNum; i++) {
		if (n[cur][i] == 1 && chk[i] != 1) {
			cnt++;
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
	dfs(1);
	cout << cnt << '\n';
}