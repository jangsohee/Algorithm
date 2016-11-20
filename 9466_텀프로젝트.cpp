#include <cstdio>

using namespace std;

int v[100002];
int chk[100002];
int cnt = 0;
bool flag = false;
void dfs(int start, int stop) {
	if (v[start] == -1 || chk[start] == 1) return;
	if (v[start] == stop) {
		chk[start] = 1;
		cnt++;
		flag = true;
		return;
	}
	
	chk[start] = 1;
	dfs(v[start], stop);
	if (flag) {
		cnt++;
	}
	else {
		chk[start] = 0;
	}
}
void init() {
	for (int i = 0; i < 100002; i++) {
		v[i] = chk[i] = 0;
		cnt = 0;
	}
}
int main() {
	int tc = 0;
	scanf("%d", &tc);
	while (tc--) {
		int n = 0; 
		scanf("%d", &n);

		init();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
			if (i == v[i]) {
				v[i] = -1;
				cnt++;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (v[v[i]] == -1) v[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			if (v[i] == -1 || chk[i] == 1) continue;
			dfs(i, i);
			flag = false;
		}
		printf("%d\n", n - cnt);
	}
	return 0;
}