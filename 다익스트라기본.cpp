#include <cstdio>

using namespace std; 

struct VERTEX {
	bool chk; //방문 체크 
	int dist; //거리
	int preV; //이전 정점
};

VERTEX v[101];
int g[101][101];

int main() {

	int n = 0;
	int v1 = 0, v2 = 0, d = 0;

	//입력
	scanf("%d", &n);
	while (scanf("%d %d %d", &v1, &v2, &d) == 3) {
		g[v1][v2] = d;
	}

	//초기화
	for (int i = 1; i <= n; i++) {
		v[i].chk = false;
		v[i].dist = 0x7fffffff; //초기값으로 최대값
		v[i].preV = 0;
	}

	//출발지
	v[1].dist = 0;

	//모든 정점을 돌고, 최단 거리 정점이 하나씩 결정
	int minV = 0;
	for (int i = 1; i <= n; i++) {
		
		int minDist = 0x7fffffff;
		for (int j = 1; j <= n; j++) {
			if (v[j].chk == false && minDist > v[j].dist) {
				minDist = v[j].dist;
				minV = j;
			}
		}

		v[minV].chk = true;

		for (int j = 1; j <= n; j++) {
			if (g[minV][j] != 0 && v[j].dist > g[minV][j] + v[minV].dist) {
				v[j].dist = g[minV][j] + v[minV].dist;
				v[j].preV = minV;
			}
		}
	}

	//출력부

	return 0;
}