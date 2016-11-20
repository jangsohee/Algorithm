#include <iostream>

using namespace std;

int map[101][101], stack[101], visit[101];
int top = -1;

int main() {
	int cnt = 0;
	int coms = 0, eNum = 0;
	cin >> coms >> eNum;

	while (eNum--) {
		int v1 = 0, v2 = 0;
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1;
	}

	stack[++top] = 1;
	while (top != -1) {
		int v = stack[top--];
		if (visit[v] == 0) {
			cnt++;
			visit[v] = 1;
			for (int i = coms; i >= 1; i--) {
				if (map[v][i] == 1) {
					stack[++top] = i;
				}
			}
		}
	}

	cout << cnt-1 << endl;

	return 0;
}