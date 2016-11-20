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
	//출력부 및 종료부
	//들어온 건 모두 소수라는 가정
	if (step == num) {
		printf("%d\n", start);
		return;
	}
	//재귀돌때마다 실행되는 것 
	start *= 10;

	//재귀돌때마다 초기화되는 것... dfs! 타고들어가고 나오면 다시들어가고!
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