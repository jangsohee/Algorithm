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

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int start = 0, stop = 0;
		cin >> start >> stop;

		if (start == stop) {
			cout << 0 << endl;
		}
		else {
			//stop이 크게 정렬
			if (start > stop) {
				int temp = start;
				start = stop;
				stop = temp;
			}

			int startH = depth(start);
			int stopH = depth(stop);
			int betDep = stopH - startH;

			//오른쪽 값 시작노드의값과 시작노드의깊이+1, 끝뎁스-시작뎁스=도는횟수
			//출발노드의 오른쪽 대각선의 끝값
			int rVal = rightVal(start, startH + 1, betDep);
			//출발노드의 왼쪽 대각선 끝값
			int leftVal = rVal - betDep;
			
			if (stop < leftVal) { //에러발생
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

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}