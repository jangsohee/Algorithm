#include <iostream>

using namespace std;

int main() {
	int res1 = 0, res2 = 0;
	int x_oneL = 0, y_basic = 0, y_basicMax = 0, y_add = 0, joi = 0;
	cin >> x_oneL >> y_basic >> y_basicMax >> y_add >> joi;

	res1 = x_oneL * joi;
	res2 = y_basic;
	if (joi > y_basicMax) {
		res2 += (joi - y_basicMax)*y_add;
	}

	if (res1 < res2) {
		cout << res1 << endl;
	}
	else {
		cout << res2 << endl;
	}
}