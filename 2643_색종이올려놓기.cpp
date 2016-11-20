#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> pa[102];
int res[102];
int num;
int main() {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		int t1 = 0, t2 = 0;
		cin >> t1 >> t2;
		if (t1 > t2) {
			int temp = t1;
			t1 = t2;
			t2 = temp;
		}
		pa[i] = make_pair(t1, t2);
	}

	sort(pa, pa + num + 1);

	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < i; j++) {
			if (pa[i].first >= pa[j].first && pa[i].second >= pa[j].second) {
				if (res[j] + 1 > res[i]) {
					res[i] = res[j] + 1;
				}
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= num; i++) {
		if (res[i] > max)	max = res[i];
	}
	cout << max << endl;
}