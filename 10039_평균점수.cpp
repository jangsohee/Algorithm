#include <iostream>

using namespace std;

int main() {
	int res = 0;
	for (int i = 0; i < 5; i++) {
		int temp = 0;
		cin >> temp;
		if (temp < 40) {
			res += 40;
		}
		else {
			res += temp;
		}
	}

	cout << res / 5 << endl;
}