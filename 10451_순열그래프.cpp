#include<iostream>


using namespace std;

int v[1002];
int chk[1002];

void dfs(int n) {
	if (chk[n] == 1) return;
	chk[n] = 1;
	dfs(v[n]);
}
int main() {
	int tc = 0;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 1002; i++) {
			v[i] = chk[i] = 0;
		}

		int num = 0;
		cin >> num;
		for (int i = 1; i <= num; i++) {
			cin >> v[i];
		}
		int ans = 0;
		for (int i = 1; i <= num; i++) {
			if (chk[i] == 0) {
				dfs(i);
				ans += 1;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}