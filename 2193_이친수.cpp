#include <iostream>

using namespace std;

long long int N[100];

int n;
int num = 0;
long long int cache[100][2];
long long int sol(int pos, int bi) {

	if (pos == n-1) {
		return 1;
	}

	long long int& ret = cache[pos][bi];
	if (ret != -1) return ret;

	if (bi == 1) {
		return ret = sol(pos + 1, 0);
	}
	else {
		return ret = sol(pos + 1, 0) + sol(pos + 1, 1);
	}
	return ret;
}
int main() {
	
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 2; j++) {
			cache[i][j] = -1;
		}
	}
	cin >> n;
	cout << sol(0, 1) << endl;
}

//int main() {
//	int n = 0;
//	cin >> n;
//
//	N[0] = N[1] = 1;
//	for (int i = 2; i < n; i++) {
//		N[i] = N[i - 1] + N[i - 2];
//	}
//	cout << N[n - 1] << endl;
//	return 0;
//}