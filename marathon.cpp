#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n = 0, e = 0;
int edge[800][800];
int node[42];
int chk[42];


void bfs(int start) {
	queue<int> que;
	que.push(start);
	chk[start] = node[start];
	for (int i = 0; i < n; i++) {
		if (i != start && edge[start][i] == 1) {
			chk[start] 
		}
	}

	while (!que.empty()) {
		
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		cin >> n >> e;
		for (int i = 0; i < n; i++) {
			scanf("%d", &node[i]);
		}
		for (int i = 0; i < e; i++) {
			int t1 = 0, t2 = 0;
			scanf("%d %d", &t1, &t2);
			edge[t1][t2] = edge[t2][t1] = 1;
		}
		//경로를 찾고
		bfs(0);
		//연결 교차로 계산

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}