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
	//위상정렬 문제지만, 위상정렬하면서 우선순위(1이 난이도가 제일 쉽고 N이 가장 어렵)가 있으므로 
	//우선순위 큐를 사용하여, - 부호 연산자를 통해 큰 값을 작은 값으로 만들어준다 (4, 3 => -3, -4)
	//priority_queue는 default가 내림차순 
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
			//큐에서 꺼낸 값과 연결된 노드와의 관계를 풀어준 뒤, 더이상 연결된 게 없다면 큐에 담아준다
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