#include <iostream>

using namespace std;

long long memo[102];

int main() {
	int n = 0;
	cin >> n;

	memo[0] = 0;
	memo[1] = 1;
	for (int i = 2; i <= n; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	cout << memo[n] << '\n';

	return 0;
}