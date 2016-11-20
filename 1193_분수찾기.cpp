#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int ch = 0, pa = 0;
	int num = 0, temp = 0;
	cin >> num;
	
	//대각선 몇 번째 줄인지
	int i = 1;
	for (; i <= 10000000; i++) {
		if (temp >= num) {
			break;
		}
		temp += i;
	}
	i--;
	//짝수 내려가는방향 
	if (i % 2 == 0) {
		ch = i;
		pa = 1;
		temp -= num;
		while (temp--) {
			ch--;
			pa++;
		}
		
	}
	else {
		ch = 1;
		pa = i;
		temp -= num;
		while (temp--) {
			ch++;
			pa--;
		}
	}

	cout << ch << '/' << pa << '\n';
	return 0;
}