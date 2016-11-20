#include <iostream>
#include <algorithm>

using namespace std;

int row, col;
int A[1024][1024];
int D[1024][1024];

int main() {
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			D[i][j] = max(D[i - 1][j], max(D[i][j - 1], D[i - 1][j - 1])) + A[i][j];
		}
	}

	cout << D[row][col] << '\n';

	return 0;
}