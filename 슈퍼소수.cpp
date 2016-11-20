#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
int num = 0;

bool isPrime(int testNum) {
	for (int i = 2; i*i <= testNum; i++) {
		if (testNum%i == 0)	{
			return false;
		}
	}
	return true;
}
void dfs(int start, int step) {
	//��º� �� �����
	//���� �� ��� �Ҽ���� ����
	if (step == num) {
		printf("%d\n", start);
		return;
	}
	//��͵������� ����Ǵ� �� 
	start *= 10;

	//��͵������� �ʱ�ȭ�Ǵ� ��... dfs! Ÿ����� ������ �ٽõ���!
	for (int j = 1; j < 10; j++) {
		start += 1;
		if (isPrime(start)) dfs(start, step + 1);
	}
}
int main() {
	scanf("%d", &num);

	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}