#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char word[201], output[201];
int en[27], leng;

void dfs(int step) {
	if (step == leng) {
		printf("%s\n", output);
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (en[i] > 0) {
			output[step] = i + 97;
			en[i]--;
			dfs(step + 1);
			en[i]++;
		}
	}
}


int main() {
	scanf("%s", &word);
	leng = strlen(word);

	for (int i = 0; i < leng; i++) {
		en[word[i] - 97] += 1;
	}

	dfs(0);
	return 0;
}
