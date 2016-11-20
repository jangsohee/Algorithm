#include <iostream>
#include <stdio.h>
using namespace std;

char map[100][100];
char res[150][150];

int r, c, R, C;
int errR, errC;

int main() {
	cin >> r >> c;
	R = 2 * r;
	C = 2 * c;
	
	int posC = C-1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("\n%c", &map[i][j]);
			res[i][j] = res[i][C - j - 1] = res[R-i-1][j] = res[R-i-1][C-j-1] = map[i][j];
		}
	}
	cin >> errR >> errC;

	if (res[errR - 1][errC - 1] == '#') res[errR - 1][errC - 1] = '.';
	else res[errR - 1][errC - 1] = '#';

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c", res[i][j]);
		}
		printf("\n");
	}
}