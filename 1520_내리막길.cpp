#include <cstdio>

int dir[4][2] = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
int A[512][512];
int D[512][512];
int x, y;

int go(int r, int c) {

	if (r == x - 1 && c == y - 1) return 1;

	if (D[r][c] > 0) return D[r][c];

	for (int i = 0; i < 4; i++) {
		int nR = r + dir[i][0];
		int nC = c + dir[i][1];

		if (nR >= 0 && nC >= 0 && nR < x && nC < y) {
			if (A[r][c] > A[nR][nC]) D[r][c] += go(nR, nC);
		}
	}
	return D[r][c];
}

int main() {
	scanf("%d %d", &x, &y);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d\n", go(0, 0));
}