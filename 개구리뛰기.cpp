#include <iostream>

using namespace std;

int v[1000002];

int main() {
	int tc = 0;
	cin >> tc;
	
	for (int i = 1; i <= tc; i++) {
		cout << "Case #" << i << '\n';

		int n = 0, k = 0;
		for (int jj = 0; jj < 1000002; jj++) {
			v[jj] = 0;
		}

		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> v[j];
		}
		cin >> k;

		int res = 0;
		int cnt = 0;
		bool flag = false;

		while (1) {

			if (v[res] == v[n]) break;
			
			int temp = 0;
			for (int ii = res; ii < n; ii++) {
				if (v[ii + 1] <= v[res] + k) {
					temp = ii + 1;
				}
				else {
					temp = ii;
					break;
				}
			}

			if (temp == res) {
				flag = true;
				break;
			}
			else {
				cnt++;
				res = temp;
			}
		}
		if (flag) cout << -1 << '\n';
		else cout << cnt << '\n';
	}
	return 0;
}


//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int n, k;
//int v[1000002];
//int chk[1000002];
//
//void init() {
//	for (int i = 0; i < 1000002; i++) {
//		v[i] = 0;
//		chk[i] = -1;
//	}
//	n = k = 0;
//}
//
//int bfs() {
//	queue<int> que;
//	//출발지 0 push
//	que.push(0);
//	//step 저장
//	chk[0] = 0;
//
//	while (!que.empty()) {
//		int nowIdx = que.front();
//		int nowPos = v[nowIdx];
//		int nowStep = chk[nowIdx];
//		que.pop();
//
//		if (nowIdx == n) {
//			return nowStep;
//		}
//
//		//인덱스에 해당하는 좌표가 갈 수 있는 길인지 판단
//		for (int i = nowIdx; i <= n; i++) {
//			int nextPos = v[i] - nowPos;
//
//			if (nextPos > v[n] || nextPos < 0)
//				continue;
//			if (chk[i] != -1 && chk[i] <= nowStep + 1)
//				continue;
//
//			if (nextPos <= k) {
//				que.push(i);
//				chk[i] = nowStep + 1;
//			}
//			else {
//				break;
//			}
//		}
//
//	}
//	return -1;
//}
//int main() {
//
//	int tc;
//	cin >> tc;
//	for (int t = 1; t <= tc; t++) {
//		init();
//
//		cout << "Case #" << t << '\n';
//		cin >> n;
//		//개구리는 0에서 출발
//		for (int i = 1; i <= n; i++) {
//			cin >> v[i];
//		}
//		cin >> k;
//		
//		cout << bfs() << '\n';
//	}
//
//	return 0;	
//}