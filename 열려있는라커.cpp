#include <iostream>
using namespace std;
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int N, K;
		cin >> N >> K;

		int lock[101];
		for (int i = 1; i < 101; i++) {
			lock[i] = 1;
		}
		for (int n = 2; n <= N; n++) {
			for (int j = 1; j <= 100; j++) {
				if (j%n == 0) {
					if (lock[j] == 1) lock[j] = 0;
					else lock[j] = 1;
				}
			}
		}
		
		cout << lock[K] << endl;

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}