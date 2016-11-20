#include <iostream>
#include <algorithm>

using namespace std;

int D[301];

int main() {
	
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cin >> D[i];
	}

	for (int i = 2; i <= num; i++) {
		D[i] = max(D[i - 1], D[i - 2]) + D[i];
	}

	cout << D[num] << endl;
	return 0;
}