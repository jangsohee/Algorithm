#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> rooms[100001];
int visit[100001];
int cnt, n, m; 
bool flag = false;

void doDFS(int start) {
	//방문
	if (visit[start] == 0) {
		visit[start] = 1;
		cnt++;
		printf("%d ", start);
	}
	//종료부
	if (cnt > n) {
		flag = true;
		return;
	}
	//재귀
	for (int i = 0; i < rooms[start].size(); i++) {
		if (visit[rooms[start].at(i)] == 0) {
			doDFS(rooms[start].at(i));
			if (flag)	return;
		}
	}
}
int main() {
	
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int n1 = 0, n2 = 0;
		scanf("%d %d", &n1, &n2);
		rooms[n1].push_back(n2);
		rooms[n2].push_back(n1);
	}

	for (int i = 1; i <= n; i++) {
		sort(rooms[i].begin(), rooms[i].end());
	}
	doDFS(1);
	return 0;
}