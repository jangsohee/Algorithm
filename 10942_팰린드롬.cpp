#include <iostream>

using namespace std;

int D[2002][2002];
int A[2002];


int go(int a, int b) {
	if (a == b) return 1;
	if (a + 1 == b) {
		if (A[a] == A[b]) return 1;
		else return 0;
	}

	if (D[a][b] != -1) return D[a][b];

	if (A[a] == A[b]) {
		return D[a][b] = go(a + 1, b - 1);
	}
	else{
		return D[a][b] = 0;
	}

	return D[a][b];
}
int main() {
	std::ios_base::sync_with_stdio(false);

	int n = 0, q = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < 2002; i++) {
		for (int j = 0; j < 2002; j++)
			D[i][j] = -1;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		cout << go(a, b) << '\n';
	}
	return 0;
}