#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char word[201], en[27];
int leng;

void dfs(int step) {
	if (step == leng) {
		cout << word << endl;
		break;
	}

	for (int i = 0; i < 26; i++) {

	}
}

int main() {
	scanf("%s", input);
	leng = strlen(input);

	for (int i = 0; i < leng; i++) {
		en[word[i] - 97] += 1;
	}
	dfs(0);
}