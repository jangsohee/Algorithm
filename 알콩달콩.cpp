/*

VCPP, GPP���� ���

*/

#include <iostream>
using namespace std;
int num[1000002];
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int N = 0, M = 0;
		int arrS = 0;
		cin >> N >> M;
		arrS = N * M;
		bool flag = true;
		int bi = 0;
		int cnt = 0;
		for (int i = 0; i < arrS; i++) {
			if (i != 0 && i % 2 == 0) {
				flag = !flag;
			}
			if(flag) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}