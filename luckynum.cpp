#include <iostream>
#include <stdio.h>

using namespace std;
int lu[2] = { 4, 7 };
int res[5];
//int bi[10] = { 0, 2, 4, 8, 16, 32, 64, 128, 246, 516 };
int bi[31];

int main() {
	int res;
	cin >> res;

	int tt = 1;
	for (int i = 1; i < 31; i++) {
		tt *= 2;
		bi[i] = tt;
	}
	//���ڸ����� �˾Ƴ���
	int t = res;
	int comp = 2;
	int idx = 1;
	while (t > comp) {
		comp += bi[++idx];
	}
	//�׷쳻���� ���° �ڸ����� �˾Ƴ���
	int start = 0;
	for (int i = 0; i < idx; i++) {
		start += bi[i];
	}
	//temp��°
	int temp = t - start;

	int idxTemp = bi[idx];
	while (idxTemp != 1) {
		//������
		idxTemp = idxTemp / 2;
		if (idxTemp < temp) {
			cout << 7;
			temp -= idxTemp;
		}
		else {
			cout << 4;
		}
		
	}
	printf("\n");
	//cout << idx << endl;
}