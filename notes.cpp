#include <iostream>

using namespace std;

int N[50001], B[50001]; //B[10001];
int nNum, qNum;

int proc(int low, int high, int fNum) {
	int mid = 0;
	bool midBig = false;
	
	while (low <= high) {
		mid = (low + high) / 2;

		if (N[mid] < fNum) {
			low = mid + 1;
			midBig = false;
		}
		else if (N[mid] > fNum) {
			high = mid - 1;
			midBig = true;
		}
		else return mid;
	}
	if (midBig) return mid;
	return mid+1;
}
int main() {
	scanf("%d %d", &nNum, &qNum);
	for (int i = 1; i <= nNum; i++) {
		scanf("%d", &B[i]);
	}
	int temp = 0;
	for (int i = 1; i <= nNum; i++) {
		temp += B[i];
		N[i] = temp - 1;
	}
	for (int i = 0; i < qNum; i++) {
		int t = 0;
		scanf("%d", &t);
		cout << proc(1, nNum, t) << endl;
	}
}