#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int num;
int up(int step) {
	
	if (step == num) return 1;
	else if (step > num) return 0;

	return up(step + 1) + up(step + 2);
}
int main() {
	cin >> num;

	cout << up(0) << endl;
}