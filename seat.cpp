#include <iostream>

using namespace std;

int N[42], M[42], cache[42][42];
int n, m;

int seat(int now, int next) {

	if (now > n || next > n) return 0;
	if (now != next) {
		if (M[now] == 1 || M[next] == 1) return 0;
	}

	if (now == n)	return 1;

	int& ret = cache[now][next];
	if (ret != -1) return ret;

	if (now < next)	return ret = seat(now + 1, now);
	else return ret = seat(now + 1, now + 1) + seat(now + 1, now + 2);
}

int main() {
	cin >> n >> m;
	//√ ±‚»≠
	for (int i = 1; i < 42; i++) {
		for (int j = 1; j < 42; j++) {
			cache[i][j] = -1;
			M[i] = -1;
		}
	}

	for (int i = 1; i <= m; i++) {
		int temp;
		cin >> temp;
		M[temp] = 1;
	}

	
	cout << seat(1, 1) + seat(1, 2) << endl;
}