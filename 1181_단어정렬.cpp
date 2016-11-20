#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

using namespace std;

char word[20001][51];

int compare(const void* a, const void* b) {
	int aNum = strlen((char*)a);
	int bNum = strlen((char*)b);

	if (aNum > bNum) {	
		return 1;
	}
	else if (aNum < bNum) {
		return -1;
	}
	else {
		return strcmp((char*)a, (char*)b);
	}
}
int main() {
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", &word[i]);
	}
	qsort(word, num, sizeof(word[0]), compare);

	printf("%s\n", word[0]);
	for (int i = 1; i < num; i++) {
		if (strcmp(word[i - 1], word[i]) != 0) 
			printf("%s\n", word[i]);
	}
}

