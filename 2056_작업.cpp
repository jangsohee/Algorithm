#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int work[10002];
int d[10002];
vector<int> v[10002];

int sol(int idx) {
	int res = 0;
	if (d[idx] != 0) return d[idx];

	for (int i = 0; i < v[idx].size(); i++) {
		int temp = 0;
		//���� �۾��� �ذ��ϱ� ���� ���
		temp = sol(v[idx].at(i));
		//���� �۾� ��, �ִ밪 ���ϱ�
		if (res < temp) res = temp;
	}
	//�ش� �ε����� �ð�(work[idx])�� ���� �۾����� ����(res, �����۾��� ���ٸ� 0) ���ؼ� ����
	return d[idx] = res + work[idx];
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> work[i];
		
		int preW = 0;
		cin >> preW;
		if (preW != 0) {
			for (int j = 0; j < preW; j++) {
				int temp = 0;
				cin >> temp;
				v[i].push_back(temp);
			}
		}
	}

	int maxRes = 0;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		temp = sol(i);
		//�� �۾����� �ɸ��� �ð��� ���ϰ� �ִ� �ð� ���� ������ش�
		if (maxRes < temp) maxRes = temp;
	}
	//��� �۾��� �Ϸ��ϱ� ���� �ּ� �ð� = �ϳ��� �۾��� �Ϸ��ϱ� ���� �ð� �� �ִ�
	cout << maxRes << '\n';
}