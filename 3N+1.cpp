#include <iostream>
#include <cmath>

using namespace std;

unsigned long long sol(unsigned long long minNum) {
	unsigned long long cnt = 0;

	while (1) {
		if (minNum <= 2) {
			cnt += 1;
			break;
		}
		if (minNum % 2 == 0) {
			minNum /= 2;
		}
		else {
			minNum *= 3;
			minNum += 1;
		}
		cnt += 1;
	}
	return cnt;
}
int main() {

	int tc = 0;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		unsigned long long k = 0, maxNum = 0, minNum = 0;
		cin >> k;

		if (k < 1) {
			minNum = maxNum = 1;
		}
		else{
			maxNum = pow(2, k);

			for (unsigned long long i = 2; i <= maxNum; i++) {
				if (sol(i) == k) {
					minNum = i;
					break;
				}
			}
		}
		
		cout << "Case #" << t << '\n';
		cout << minNum << " " << maxNum << '\n';
	}

	return 0;
}