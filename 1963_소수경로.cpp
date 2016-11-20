#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int start, stop;
int minStep = -1;

using namespace std;

bool isPrime(int num) {
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0)	return false;
	}
	return true;
}
void doBFS(int cur) {
	int chk[10000] = { 0, };
	queue<int> que;

	que.push(cur);
	chk[cur] = 0;

	while (!que.empty()) {
		int nowNum = que.front();
		int nowStep = chk[nowNum];
		que.pop();


		if (nowNum == stop) {
			minStep = nowStep;
			return;
		}

		for (int i = 0; i <= 9; i++) { //1234

			int th = (nowNum / 1000); //1
			int hun = ((nowNum % 1000) / 100); //2
			int ten = (nowNum % 1000 % 100) / 10; //3 
			int one = nowNum % 1000 % 100 % 10; //4

			int cTh = (i * 1000) + (hun * 100) + (ten * 10) + one;
			int cHun = (th * 1000) + (i * 100) + (ten * 10) + one;
			int cTen = (th * 1000) + (hun * 100) + (i * 10) + one;
			int cOne = (th * 1000) + (hun * 100) + (ten * 10) + i;

			if (cTh >= 1000 && isPrime(cTh) && chk[cTh] == 0) {
				que.push(cTh);
				chk[cTh] = nowStep + 1;
			}
			if (cHun >= 1000 && isPrime(cHun) && chk[cHun] == 0) {
				que.push(cHun);
				chk[cHun] = nowStep + 1;
			}
			if (cTen >= 1000 && isPrime(cTen) && chk[cTen] == 0) {
				que.push(cTen);
				chk[cTen] = nowStep + 1;
			}
			if (cHun >= 1000 && isPrime(cOne) && chk[cOne] == 0) {
				que.push(cOne);
				chk[cOne] = nowStep + 1;
			}
		}
	}
}
int main() {
	int tc = 0;
	cin >> tc;
	while (tc--) {
		minStep = -1;
		start = stop = 0;

		cin >> start >> stop;

		if (start == stop) {
			cout << 0 << endl;
		}
		else {
			doBFS(start);
			if (minStep == -1) {
				cout << "Impossible" << endl;
			}
			else{
				cout << minStep << endl;
			}
		}

	}

	return 0;
}
