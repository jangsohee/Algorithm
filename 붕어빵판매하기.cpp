#include <iostream>
#include <algorithm>

using namespace std;

int d[1002];
int p[1002];

int main() {
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], p[j] + d[i - j]);
		}
	}

	cout << d[n] << '\n';
	return 0;
}