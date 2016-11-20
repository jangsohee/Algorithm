#include <iostream>

using namespace std;

int N = 0, K = 0, L = 0;
long long d[50002][102] = { 0, };
int x[25002] = { 0, };

void init() {
	for (int i = 0; i < 50002; i++) {
		for (int j = 0; j < 102; j++) {
			d[i][j] = 0;
		}
	}

	for (int i = 0; i < 25002; i++) {
		x[i] = 0;
	}
	N = K = L = 0;
}
bool chk(int n) {
	for (int i = 0; i < L; i++) {
		if (x[i] == n) {
			return true;
		}
	}
	return false;
}
int main() {
	int tc = 0;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cout << "Case #" << t << '\n';
		init();

		cin >> N >> K >> L;
		for (int i = 0; i < L; i++) {
			cin >> x[i];
		}

		d[0][1] = 1;
		d[1][1] = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				if (i - j < 0) break;
				if (chk(i)) break;

				d[i][j] += d[i - j][j];
				d[i][j] %= 1000000009;
			}
		}

		long long res = 0;
		for (int i = 1; i <= K; i++) {
			res += d[N][i];
			res %= 1000000009;
		}
		cout << res << '\n';
	}

	return 0;
}