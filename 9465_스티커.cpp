#include <iostream>
#include <algorithm>

using namespace std;

int s[2][100002];
int d[2][100002];

int main() {
	int tc = 0;
	cin >> tc;

	while (tc--) {
		int n = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 100002; j++) {
				s[i][j] = d[i][j] = 0;
			}
		}

		cin >> n;


		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}

		d[0][0] = s[0][0];
		d[1][0] = s[1][0];

		for (int j = 1; j < n; j++) {
			d[0][j] = max(d[0][j - 1], d[1][j-1] + s[0][j]);
			d[1][j] = max(d[0][j - 1] + s[1][j], d[1][j - 1]);
		}

		cout << max(d[0][n-1], d[1][n-1]) << '\n'; 
	}

	return 0;
}