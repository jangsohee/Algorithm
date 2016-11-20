#include <iostream>
#include <queue>

#define MAX 100000
#define MIN 0
using namespace std;

int start, stop;
int check[100001];
queue<int> que;
int timer;

void bfs() {
	que.push(start);
	check[start] = 0;
	while (!que.empty()) {
		int now = que.front();
		int step = check[now] + 1;
		que.pop();

		if (now == stop) {
			printf("%d\n", check[now]);
			break;
		}
		
		if (now * 2 <= MAX && check[now * 2] == 0) {
			check[now * 2] = step;
			que.push(now * 2);
		}
		if (now +1 <= MAX && check[now + 1] == 0) {
			check[now + 1] = step;
			que.push(now + 1);
		}
		if (now - 1 >= MIN && check[now - 1] == 0) {
			check[now - 1] = step;
			que.push(now - 1);
		}
	}
}
int main(){
	scanf("%d %d", &start, &stop);
	if (start > stop) {
		printf("%d\n", start - stop);
	}
	else {
		bfs();
	}
	return 0;
}