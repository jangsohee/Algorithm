#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

queue<int> que;
int start, stop;
int check[10000];

bool isPrime(int num) {
	for (int i = 2; i*i <= num; i++){
		if (num%i == 0)
			return false;
	}
	return true;
}
void bfs(int s) {
	que.push(s);
	check[s] = 0;

	while (!que.empty()) {
		int now = que.front();
		int nowDepth = check[now];
		que.pop();
		
		
		if (now == stop) {
			printf("%d\n", check[now]);
			break;
		}

		for (int i = 0; i <= 9; i++) {
			int th = now / 1000;
			int hun = (now % 1000) / 100;
			int ten = ((now % 1000) % 100) / 10;
			int one = now % 1000 % 100 % 10;

			int changeTh = (i * 1000 + hun * 100 + ten * 10 + one);
			int changeHun = (th * 1000 + i * 100 + ten * 10 + one);
			int changeTen = (th * 1000 + hun * 100 + i * 10 + one);
			int changeOne = (th * 1000 + hun * 100 + ten * 10 + i);

			//천
			if (i != 0 && isPrime(changeTh) && check[changeTh] == 0) {
				check[changeTh] = nowDepth + 1;
				que.push(changeTh);
			}
			//백
			if (isPrime(changeHun) && check[changeHun] == 0) {
				check[changeHun] = nowDepth + 1;
				que.push(changeHun);
			}
			//십
			if (isPrime(changeTen) && check[changeTen] == 0) {
				check[changeTen] = nowDepth + 1;
				que.push(changeTen);
			}
			//일
			if (isPrime(changeOne) && check[changeOne] == 0) {
				check[changeOne] = nowDepth + 1;
				que.push(changeOne);
			}
		}
	}
}
int main() {
	scanf("%d %d", &start, &stop);
	if (start == stop) {
		cout << 0 << endl;
	}
	else {
		bfs(start);
	}
	return 0;
}