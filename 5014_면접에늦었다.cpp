#include <iostream>
#include <queue>

using namespace std;

int all, start, stop, up, down;
queue<int> que;
int chk[1000003];

void bfs(int cur) {
	que.push(cur);
	chk[cur] = 0;

	while (!que.empty()) {
		int n = que.front();
		int nowStep = chk[n];
		que.pop();

		if (n == stop) {
			return;
		}

		int uNum = n + up;
		int dNum = n - down;

		if (uNum >= start && uNum <= all && chk[uNum] == -1) {
			que.push(uNum);
			chk[uNum] = nowStep + 1;
		}
		if (dNum > 0 && dNum <= all && chk[dNum] == -1) {
			que.push(dNum);
			chk[dNum] = nowStep + 1;
		}
		
	}
}


int main() {
	cin >> all >> start >> stop >> up >> down;

	for (int i = 0; i <= all; i++) {
		chk[i] = -1;
	}

	bfs(start);
	if (chk[stop] == -1) {
		cout << "use the stairs" << endl;
	}
	else {
		cout << chk[stop] << endl;
	}

	return 0;
}