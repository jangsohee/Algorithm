#include <iostream>

using namespace std;

int n[500001];
int num = 0, fNum = 0;

int proc(int low, int high) {
	int mid = 0;
	int cnt = 0;

	while (low <= high) {
		cnt++;
		mid = (low + high) / 2;
		if (n[mid] < fNum) {
			low = mid + 1;
		}
		else if (n[mid] > fNum) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
int main(){
	int res = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &n[i]);
	}
	scanf("%d", &fNum);
	
	res = proc(1, num);
	if (res == -1)
		cout << "not found" << endl;
	else
		cout << res << endl;
}