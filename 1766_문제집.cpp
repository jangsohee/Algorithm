#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32002];
priority_queue<int> que;
int chk[32002];
int node, edge;

int main() {
	cin >> node >> edge;
	for (int i = 0; i < edge; i++) {
		int t1 = 0, t2 = 0;
		cin >> t1 >> t2;
		v[t1].push_back(t2);
		chk[t2]++;
	}
	//�������� ��������, ���������ϸ鼭 �켱����(1�� ���̵��� ���� ���� N�� ���� ���)�� �����Ƿ� 
	//�켱���� ť�� ����Ͽ�, - ��ȣ �����ڸ� ���� ū ���� ���� ������ ������ش� (4, 3 => -3, -4)
	//priority_queue�� default�� �������� 
	for (int i = 1; i <= node; i++) {
		if (chk[i] == 0) {
			que.push(-i);
		}
	}

	while (!que.empty()) {
		int nowNode = -que.top();
		que.pop();

		cout << nowNode << " ";
		for (int i = 0; i < v[nowNode].size(); i++) {
			//ť���� ���� ���� ����� ������ ���踦 Ǯ���� ��, ���̻� ����� �� ���ٸ� ť�� ����ش�
			int nextNode = v[nowNode].at(i);
			chk[nextNode] -= 1;

			if (chk[nextNode] == 0) {
				que.push(-nextNode);
			}
		}
	}

	cout << '\n';
	return 0;
}