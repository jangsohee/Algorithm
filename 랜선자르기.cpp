#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

unsigned int N[10001], nNum, kNum;
unsigned int res = 0;

void bs(unsigned int low, unsigned int high) {
	unsigned int mid;
	
	while (low <= high) {
		
		unsigned int cnt = 0;
		mid = (low + high)/2;
		
		for (int i = 0; i < nNum; i++) {
			cnt += N[i] / mid;
		}
		if (cnt < kNum) {
			high = mid - 1;
		}
		else{
			res = mid;
			low = mid + 1;
		}
	}
}
int main() {
	scanf("%d %d", &nNum, &kNum);

	for (int i = 0; i < nNum; i++) {
		scanf("%d", &N[i]);
	}

	bs(0, 2147483647);
	cout << res << endl;
}
