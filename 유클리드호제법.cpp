#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int lcm(int x, int y) {
	int minNum = min(x, y);
	while (1) {
		if (minNum%x == 0 && minNum%y == 0) {
			break;
		}
		else{
			minNum++;
		}
	}
	return minNum;
}
int gcd(int x, int y) {
	int minNum = min(x, y);

	for (int i = minNum; i > 0; i--) {
		if (x%i == 0 && y%i == 0) {
			minNum = i;
			break;
		}
	}
	return minNum;
}
int main() {
	int a, b;
	cin >> a >> b;
	
	printf("%d %d\n", gcd(a, b), lcm(a, b));
}