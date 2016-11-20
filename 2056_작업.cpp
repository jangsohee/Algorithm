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
		//선행 작업을 해결하기 위한 재귀
		temp = sol(v[idx].at(i));
		//선행 작업 중, 최대값 구하기
		if (res < temp) res = temp;
	}
	//해당 인덱스의 시간(work[idx])과 선행 작업들의 값을(res, 선행작업이 없다면 0) 더해서 리턴
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
		//각 작업마다 걸리는 시간을 구하고 최대 시간 값을 출력해준다
		if (maxRes < temp) maxRes = temp;
	}
	//모든 작업을 완료하기 위한 최소 시간 = 하나의 작업을 완료하기 위한 시간 중 최대
	cout << maxRes << '\n';
}