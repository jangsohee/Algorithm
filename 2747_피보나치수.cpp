#include <iostream>

using namespace std;

int fNum;
int n[50];
int fibo(int num) {

	if (num <= 1) {
		return num;
	}
	else if (n[num] != 0) {
		return n[num];
	}
	else {
		return n[num] = fibo(num - 1) + fibo(num - 2);
	}
}
int main() {
	cin >> fNum;
	cout << fibo(fNum) << endl;

	return 0;
}