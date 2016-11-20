#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int testCase = 0;
	int xPos[4] = { 0, };
	int yPos[4] = { 0, };

	cin >> testCase;

	while (testCase--) {
		bool isSquare = false;
		int line1 = 0, line2 = 0, line3 = 0;

		for (int i = 0; i < 4; i++) {
			cin >> xPos[i] >> yPos[i];
		}
		
		//기준점과 연결된 3개의 직선
		line1 = pow(xPos[1] - xPos[0], 2) + pow(yPos[1] - yPos[0], 2);
		line2 = pow(xPos[2] - xPos[0], 2) + pow(yPos[2] - yPos[0], 2);
		line3 = pow(xPos[3] - xPos[0], 2) + pow(yPos[3] - yPos[0], 2);

		//가로^2 * 세로^2 = 빗변^2
		// 빗변 = 루트2
		//가로:루트x 세로: 루트x 빗변: 루트2x 
		//루트를 제외하고 루트 안의 값만 비교했을 때, x에 2를 곱한값이 나머지 선분이 되야함 
		if (line1 == line2 || line1 == line3 || line2 == line3) {
			if (line1 == line2) {
				if (line1 * 2 == line3) {
					isSquare = true;
				}
			}
			else if (line1 == line3) {
				if (line1 * 2 == line2) {
					isSquare = true;
				}
			}
			else if (line2 == line3) {
				if (line2 * 2 == line1) {
					isSquare = true;
				}
			}
		}
		
		if (isSquare) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}