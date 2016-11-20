#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

queue<int> que;
vector<int> gra[1000000];
int check[1000000];
int peo, com;
int p, q;

int bfs(int start, bool pStart) {
	que.push(start);
	check[start] = 0;

	while (!que.empty()) {
		int now = que.front();
		int nowStep = check[now];
		que.pop();

		if (pStart){
			if (now == q) {
				return nowStep;
			}
		}
		else {
			if (now == p) {
				return nowStep;
			}
		}
		

		for (int i = 0; i < gra[now].size(); i++) {
			int next = gra[now].at(i);
			if (check[next] == -1) {
				check[next] = nowStep + 1;
				que.push(next);
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d %d", &peo, &com);
	for (int i = 0; i < com; i++) {
		int temp1 = 0, temp2 = 0;
		scanf("%d %d", &temp1, &temp2);
		gra[temp1].push_back(temp2);
	}
	scanf("%d %d", &p, &q);
	
	memset(check, -1, sizeof(check));
	int pTemp = bfs(p, true);
	memset(check, -1, sizeof(check));
	int qTemp = bfs(q, false);

	if (pTemp > qTemp) {
		printf("yes\n");
	}
	else if (pTemp < qTemp){
		printf("no\n");
	}
	else if(pTemp == qTemp){
		printf("unknown\n");
	}

	return 0;
}