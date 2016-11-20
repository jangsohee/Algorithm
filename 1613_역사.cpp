#include <cstdio>
#include <cstring>

int v[402][402];
int chk[402];
int e, r;

int main() {
	scanf("%d %d", &e, &r);
	for (int i = 0; i < r; i++) {
		int t1 = 0, t2 = 0;
		scanf("%d %d", &t1, &t2);
		v[t1][t2] = 1;
	}


	for (int k = 1; k <= e; k++) {
		for (int i = 1; i <= e; i++) {
			for (int j = 1; j <= e; j++) {
				v[i][j] |= v[i][k] && v[k][j];
			}
		}
	}
	int tc = 0;
	scanf("%d", &tc);
	while (tc--) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);

		if (v[n1][n2]) {
			printf("-1\n");
		}
		else if (v[n2][n1]) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
		
	}

	return 0;
}