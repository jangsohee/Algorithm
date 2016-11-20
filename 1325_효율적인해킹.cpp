#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v[10001];
int com[10001];
int visit[10001];
int N, M;
int maxRes = 0;
int res = 0;

void dfs(int cur) {
	maxRes++;
	visit[cur] = 1;
	int leng = v[cur].size();
	for (int i = 0; i < leng; i++) {
		if (visit[v[cur][i]] != 1) {
			dfs(v[cur][i]);
		}
	}
}
int main() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int t1 = 0, t2 = 0;
		cin >> t1 >> t2;
		v[t2].push_back(t1);
	}
	for (int i = 1; i <= N; i++) {
		dfs(i);
		com[i] = maxRes;
		if (maxRes > res)	res = maxRes;
		memset(visit, 0, sizeof(visit));
		maxRes = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (com[i] == res) {
			printf("%d ", i);
		}
	}
}