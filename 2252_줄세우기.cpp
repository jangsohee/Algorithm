#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
int sNum, edge;
queue<int> que;
vector<int> v[32002];
int chk[32002];

int main() {
	cin >> sNum >> edge;
	for (int i = 0; i < edge; i++) {
		int t1 = 0, t2 = 0;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		chk[t2]++;
	}
	//chk == 0 �� �͵��� �켱 ť�� ���
	for (int i = 1; i <= sNum; i++) {
		if (chk[i] == 0) {
			que.push(i);
		}
	}
	
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		printf("%d ", now); //����ϰ�
		//����� ����� chk�� �ٿ��ش�, ���⼭ chk�� 0�̸� ť������ش�
		int vSize = v[now].size();
		if (vSize != 0) {
			for (int i = 0; i < vSize; i++) {
				int node = v[now].at(i);
				chk[node]--;
				if (chk[node] == 0) {
					que.push(node);
				}
			}
		}
	}
	printf("\n");
	return 0;
}