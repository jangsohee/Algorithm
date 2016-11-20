#include <iostream>

using namespace std;

int N[30];
int n, k;


void sol(int nNum, int kNum) {
	
	if (nNum > n || kNum > k) return;
	if (nNum == n && kNum == k) {
		for (int i = 0; i < n; i++) {
			cout << N[i];
		}
		printf("\n");
		return;
	}

	N[nNum] = 1;
	sol(nNum + 1, kNum + 1);
	N[nNum] = 0;
	sol(nNum + 1, kNum);
}

int main() {
	cin >> n >> k;
	sol(0, 0);
	return 0;
}