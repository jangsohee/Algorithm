#include <iostream>
#include <algorithm>

using namespace std;

struct Jewel {
	int wei;
	int val;
};

bool cmpWei(Jewel w1, Jewel w2) {
	return w1.wei < w2.wei;
}
int main() {
	int tc = 0;
	cin >> tc;

	for (int ii = 1; ii <= tc; ii++) {
		Jewel jewel[1001] = { 0, };
		int back[10001] = { 0, };

		int jNum = 0, bWei = 0;
		cin >> jNum >> bWei;
		for (int i = 0; i < jNum; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			jewel[i].wei = t1;
			jewel[i].val = t2;
		}
		sort(jewel, jewel + jNum, cmpWei);

		for (int i = 0; i < jNum; i++) {
			for (int bw = 1; bw <= bWei; bw++) {
				int jw = jewel[i].wei;
				int jVal = jewel[i].val;
				if (jw <= bw && jVal + back[bw - jw] > back[bw])
					back[bw] = jVal + back[bw - jw];
			}
		}
		cout << "#testcase" << ii << endl;
		cout << back[bWei] << endl;
	}
}