#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue<pair<int, int> > que;
char bang[1000][1000];
int res[1000][1000];
int nSize;
int minNum;

void bfs(int r, int c, int step) {
	
}
int main() {
	cin >> nSize;
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			scanf("\n%c", bang[i][j]);
		}
	}

	bool flag = false;
	for (int i = 0; i < nSize; i++) {
		for (int j = 0; j < nSize; j++) {
			if (bang[i][j] == '#') {
				bfs(i, j, 0);
				flag = true;
				break;
			}
			if (flag) break;
		}
	}
	
	cout << minNum << endl;
	return 0;
}