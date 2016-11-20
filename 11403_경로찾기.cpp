#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int map[102][102];
int visit[102];
int node = 0;

void dfs(int start) {
	for (int i = 0; i < node; i++) {
		if (map[start][i] == 1 && visit[i] != 1) {
			visit[i] = 1;
			dfs(i);
		}
	}
}
int main() {

	cin >> node;
	for (int i = 0; i < node; i++) {
		for (int j = 0; j < node; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < node; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
		for (int j = 0; j < node; j++) {
			if (visit[j] == 1) {
				printf("1 ");
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
	
	return 0;
}