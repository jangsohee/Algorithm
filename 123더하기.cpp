#include <iostream>

using namespace std;

int d[12];

int main() {
	
	d[0] = 1;
	for (int i = 1; i <= 11; i++) {
		if (i-1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i-2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i-3 >= 0) {
			d[i] += d[i - 3];
		}
	}


	int tc = 0;
	cin >> tc;
	while (tc--) {
		int n = 0; 
		cin >> n;
		cout << d[n] << '\n';
	}
	return 0;
}