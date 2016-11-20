/* Ω∫≈√ */

#include <iostream>

using namespace std;

int top = -1;
int map[11][11];
int stack[11];
int visit[11]; 

int main() {
	
	int vNum, sNum;
	int v1, v2;
	cin >> vNum >> sNum;

	while (!cin.eof()) {
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1;
	}

	stack[++top] = sNum;
	while (top != -1) {
		int v = stack[top--];
		if (visit[v] == 0) {
			cout << v << ' ';
			visit[v] = 1;
			for (int i = vNum; i >= 1; i--) {
				if (map[v][i] == 1) {
					stack[++top] = i;
				}
			}
		}
	}
	
	return 0;
}

/* ¿Á±Õ */

//#include <iostream>
//
//using namespace std;
//
//int node[11][11] = { 0, };
//int vNum = 0, startNode = 0;
//int visit[11] = { 0, };
//
//void dfs(int start) {
//	cout << start << " ";
//	visit[start] = 1;
//
//	for (int i = 1; i <= vNum; i++) {
//		if (node[start][i] == 1 && visit[i] != 1) {
//			node[start][i] = node[i][start] = 0;
//			dfs(i);
//		}
//	}
//}
//
//int main() {
//
//	cin >> vNum >> startNode;
//
//	while (!cin.eof()) {
//		int i = 0, j = 0;
//		cin >> i >> j;
//		node[i][j] = node[j][i] = 1;
//	}
//	dfs(startNode);
//
//	return 0;
//}