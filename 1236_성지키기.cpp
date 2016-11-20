#include <iostream>
#include <stdio.h>

using namespace std;

char s[51][51];
bool row[51] = {false, };
bool col[51] = {false, };
int x, y;


int main() {
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x; i++) {
		cin >> s[i];
	}
	 
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (s[i][j] == 'X') {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < x; i++) {
		if (row[i] == false) cnt1++;
	}

	for (int i = 0; i < y; i++) {
		if (col[i] == false) cnt2++;
	}

	if (cnt1 > cnt2)
		cout << cnt1 << '\n';
	else
		cout << cnt2 << '\n';

	return 0;
}