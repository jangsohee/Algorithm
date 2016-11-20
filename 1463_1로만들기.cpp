#include <iostream>
#include <queue>

using namespace std;

queue<int> que;
int chk[1000000];
int num;

void bfs(int start) {
	que.push(start);
	chk[start] = 0;

	while (!que.empty()) {
		int now = que.front();
		int nowStep = chk[now];
		que.pop();

		if (now == 1) {
			cout << nowStep << endl;
			return;
		}
		if (now % 3 == 0) {
			if (chk[now / 3] == -1 || (chk[now / 3] != -1 && chk[now / 3] > nowStep + 1)) {
				que.push(now / 3);
				chk[now / 3] = nowStep + 1;
			}
		}
		if (now % 2 == 0) {
			if (chk[now / 2] == -1 || (chk[now / 2] != -1 && chk[now / 2] > nowStep + 1)) {
				que.push(now / 2);
				chk[now / 2] = nowStep + 1;
			}
		}
		if (chk[now-1] == -1 || (chk[now-1] != -1 && chk[now-1] > nowStep + 1)) {
			que.push(now - 1);
			chk[now - 1] = nowStep + 1;
		}
	}
}

int main() {
	cin >> num;
	for (int i = 0; i <= num; i++)	chk[i] = -1;
	bfs(num);
}