#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char word[20];
char res[5][100];
char p[5][5] = { "..#.", ".#.#", "#.X.", ".#.#", "..#." };
char w[5][5] = { "..*.", ".*.*", "*.X.", ".*.*", "..*." };
char lastP[] = "..#..";
char lastW[] = "..*..";

void wendy(char c) {

}
int main() {
	cin >> word;
	int num = strlen(word);

	int cSize = (num * 5) - (num-1);
	int wSize = 4 * (num - 1);

	int xCol = 2;
	int wPos = 0;
	int wenStart = 8;
	int wenStop = 12;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < cSize-1; j++) {
			if (j%12 >= wenStart && j%12 < wenStop) {
				//3��� - ����
				res[i][j] = w[i][j % 4];
			}
			else {	
				//����
				//��ĥ��쿡�� ������������ ����
				if (res[i][j] == '*') continue;
				res[i][j] = p[i][j % 4];
			}
			//Xǥ��
			if (i == 2 && j == xCol) {
				res[i][j] = word[wPos++];
				xCol += 4;
			}
		}
	}
	int aster = 12;
	while (cSize >= aster) {
		for (int i = 0; i < 5; i++) {
			res[i][aster] = lastW[i];
		}
		aster += 12;
	}
	

	if (num % 3 != 0) {
		for (int i = 0; i < 5; i++) {
			res[i][cSize - 1] = lastP[i];
		}
	}
	else {
		for (int i = 0; i < 5; i++) {
			res[i][cSize-1] = lastW[i];
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << res[i] << endl;
	}
}