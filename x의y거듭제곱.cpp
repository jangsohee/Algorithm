#include <iostream>

using namespace std;

int pow(int x, int y) {
	if (y == 1) return x;
	return x * pow(x, y - 1);
}
int main() {
	int a, b;
	cin >> a >> b;

	cout << pow(a, b) << endl;
}