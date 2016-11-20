#include <iostream>

using namespace std;

int d[41][2];

int main() {

	int tc = 0;
	cin >> tc;

	d[0][0] = 1;
	d[1][1] = 1;
	while (tc--) {
		int N = 0;
		cin >> N;
		
		if(N >= 2) {
			for (int i = 2; i <= N; i++) {
				d[i][0] = d[i - 1][0] + d[i - 2][0];
				d[i][1] = d[i - 1][1] + d[i - 2][1];
			}
		}
		cout << d[N][0] << ' ' << d[N][1] << '\n';
	}
	return 0;
}