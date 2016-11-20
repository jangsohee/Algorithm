#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
int num = 0;
char arr[20] = { 0, };  
char bet[3] = {' ', '+', '-'};

bool isZero() {
	int res = 0, val = 0;
	bool add = true;
	for (int i = 1; i <= num + (num - 1); i++) {
		switch (arr[i]) {
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				val += arr[i] - '0';
				break;
			case '+':
				if (add) {
					res += val;
					val = 0;
				}
				else {
					res -= val;
					val = 0;
					add = true;
				}
				break;
			case '-':
				if (add) {
					res += val;
					val = 0;
					add = false;
				}
				else {
					res -= val;
					val = 0;
				}
				break;
			case ' ':
				val *= 10;
				break;
		}
	}
	if (add) {
		res += val;
	}
	else {
		res -= val;
	}
	if (res == 0) return true;
	else return false;
}

void dfs(int start) {
	if (start >= num + (num - 1)) {
		if (isZero()) {
			for (int i = 1; i < num + num; i++) {
				printf("%c", arr[i]);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		arr[start] = bet[i];
		dfs(start + 2);
		arr[start] = '?';
	}
}

int main() {
	char res = '1';
	bool isNum = true;
	scanf("%d", &num);

	for (int i = 1; i <= num + (num - 1); i++) {
		if (isNum) {
			isNum = false;
			arr[i] = res++;
		}
		else {
			isNum = true;
			arr[i] = '?';
		}
	}

	dfs(2);
	
	return 0;
}