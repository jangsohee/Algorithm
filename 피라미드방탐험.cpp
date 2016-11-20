#include <iostream>
#include <stdio.h>
using namespace std;

int depth(int node) {
	int h = 1;
	int rVal = 1;
	int oper = 2;
	while (rVal < node) {
		rVal += oper;
		h++;
		oper++;
	}
	return h;
}

int rightVal(int startNode, int firstOper, int loofNum) {
	int res = startNode;
	int oper = firstOper;
	for (int i = 0; i < loofNum; i++) {
		res += oper;
		oper++;
	}
	return res;
}
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int start = 0, stop = 0;
		cin >> start >> stop;

		if (start == stop) {
			cout << 0 << endl;
		}
		else {
			//stop�� ũ�� ����
			if (start > stop) {
				int temp = start;
				start = stop;
				stop = temp;
			}

			int startH = depth(start);
			int stopH = depth(stop);
			int betDep = stopH - startH;

			//������ �� ���۳���ǰ��� ���۳���Ǳ���+1, ������-���۵���=����Ƚ��
			//��߳���� ������ �밢���� ����
			int rVal = rightVal(start, startH + 1, betDep);
			//��߳���� ���� �밢�� ����
			int leftVal = rVal - betDep;
			
			if (stop < leftVal) { //�����߻�
				cout << betDep + (leftVal - stop) << endl;
			}
			else if (rVal < stop) {
				cout << betDep + (stop - rVal) << endl;
			}
			else {
				cout << betDep << endl;
			}
		}
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}