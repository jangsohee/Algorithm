#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long N[10002];
int nNum;

int main() {

	cin >> nNum;

	if (nNum == 0) {
		cout << 5 << '\n';
		return 0;
	}
	for (int i = 0; i < nNum; i++) {
		cin >> N[i];
	}



	sort(N, N + nNum);

	unsigned long long minCnt = 1;
	unsigned long long temp = 1;
	for (int i = 0; i < nNum - 1; i++) {
		if (N[i] + 1 == N[i+1]) {
			temp += 1;
		}
		else{
			if (minCnt < temp) {
				minCnt = temp;
			}
			temp = 1;
		}
	}
	
	if (minCnt < temp) {
		minCnt = temp;
	}

	unsigned long long res = 5;
	res -= minCnt;

	if (res <= 0) {
		cout << 0 << '\n';
	}
	else{
		cout << 5 - minCnt << '\n';
	}
	

	return 0;
}