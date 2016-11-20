#include <iostream>

using namespace std;

int n, eNum;
int com[1024][1024];
int edge[1024][1024];
int chk[1024];

int main() {
	cin >> n >> eNum;
	for (int i = 0; i < eNum; i++) {
		int v1 = 0, v2 = 0, val = 0;
		cin >> v1 >> v2 >> val;
		com[v1][v2] = val;
		com[v2][v1] = val;
	}

	int edgeNum = 0;
	while (edgeNum != n - 1) {

	}
	
}