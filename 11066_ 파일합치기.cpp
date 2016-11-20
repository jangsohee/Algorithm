#include <iostream>
#include <algorithm>

using namespace std;

int D[512][512];
int A[512];

int main() {

	int tc = 0;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i < 512; i++) {
			A[i] = 0;
			for (int j = 0; j < 512; j++) {
				D[i][j] = 0;
			}
		}
		
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}

		int k = n/2; //n¿∫ 3¿ÃªÛ
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				D[i][j] = min(D[i][k], D[k + 1][j]) + A[i];
			}
		}
	}

	return 0;
}