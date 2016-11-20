#include <iostream>

using namespace std;

int main() {
	int num = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		bool flag = false;
		int temp = 0;
		cin >> temp;

		for (int m = 2; m <= 64; m++) {
			bool tempFlag = true;
			int val = temp;
			int mod[20];
			int res[20];
			int idx = 0;
			while (val >= m) {
				mod[idx++] = val%m;
				val = val / m;
			}
			mod[idx] = val;
			for (int i = 0; i <= idx; i++) {
				if (mod[i] != mod[idx - i]) {
					tempFlag = false;
				}
			}
			if (tempFlag) {
				flag = true;
				break;
			}
		}
		if (flag)	cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}