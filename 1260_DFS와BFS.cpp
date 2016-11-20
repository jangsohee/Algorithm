#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int nNum, eNum, start;
vector<int> e[10001];
int visit[10001];


void dfs(int cur) {
	printf("%d ", cur);
	visit[cur] = 1;

	for (int i = 0; i < e[cur].size(); i++) {
		int temp = e[cur][i];
		if (visit[temp] != 1) {
			dfs(temp);
		}
	}
}
void bfs(int cur) {
	queue<int> que;
	que.push(cur);
	visit[cur] = 1;

	while (!que.empty()) {
		int now = que.front();
		que.pop();
		printf("%d ", now);

		for (int i = 0; i < e[now].size(); i++)  {
			int temp = e[now][i];
			if (visit[temp] != 1) {
				visit[temp] = 1;
				que.push(temp);
			}
		}
	}
}

int main() {
	cin >> nNum >> eNum >> start;
	for (int i = 0; i < eNum; i++) {
		int t1 = 0, t2 = 0;
		scanf("%d %d", &t1, &t2);
		e[t1].push_back(t2);
		e[t2].push_back(t1);
	}
	for (int i = 1; i <= nNum; i++) {
		sort(e[i].begin(), e[i].end());
	}
	dfs(start);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	bfs(start);
	printf("\n");
}