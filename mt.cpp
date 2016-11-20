#include <stdio.h>
#include <iostream>

using namespace std;

int num;
void print(int n) {	
	if (n > 0){
		print(n - 1);
		print(n - 1);
		printf("%d", n);
		
	}
}
int main() {
	cin >> num;
	print(num);
	return 0;
}