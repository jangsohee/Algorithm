#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int m[4] = { 25, 10, 5, 1 };
	int money = 0;
	
	cin >> money;
	
	for (int i = 0; i < 4; i++) {
		int cnt = money / m[i];
		money = money % m[i];
		m[i] = cnt;
	}
		
	cout << m[0] << " QUARTER(S), " << m[1] << " DIME(S), " << m[2] << " NICKEL(S), " << m[3] << " PENNY(S) " << endl;
}