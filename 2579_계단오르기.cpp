#include <iostream>
#include <algorithm>

using namespace std;

int a[305];
int d[305][3];

int main() {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	//d[1][0] = 0;
	d[1][1] = a[1];
	//d[2][0] = a[1];
	d[2][1] = a[2];
	d[2][2] = a[1] + a[2];
	d[3][1] = a[3];
	d[3][2] = a[2] + a[3];
	for (int i = 3; i <= n; i++) {
		//d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
		d[i][1] = max(d[i - 2][0], max(d[i - 2][1], d[i - 2][2])) + a[i];
		d[i][2] = max(d[i - 3][0], max(d[i - 3][1], d[i - 3][2])) + a[i] + a[i - 1];
	}

	cout << max(d[n][1], d[n][2]) << '\n';

	return 0;
}