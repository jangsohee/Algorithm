#include <iostream>

using namespace std;

int n;
int t[502];
int g[502][502];
int d[502];

int sol(int idx) {
	int retMax = 0;
	if (d[idx] != 0) return d[idx];

	for (int i = 1; i <= n; i++) {
		if (g[idx][i] == 1) {
			int temp = 0;
			temp = sol(i);
			//��� �ǹ��� ���µ� �ּ� �ð� = ����Ǿ�� �� �ǹ����� �ð� �� �ִ� �� 
			if (retMax < temp) retMax = temp;
		}
	}
	return d[idx] = t[idx] + retMax;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];

		while (1) {
			int j = 0;
			cin >> j;
			if (j == -1) break;
			g[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << sol(i) << '\n';
	}
	return 0;
}