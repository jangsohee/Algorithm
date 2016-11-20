#include <iostream>

using namespace std;

int cache[102][102];
int map[102][102];
int mSize;

int jump(int r, int c) {
	if (r >= mSize || c >= mSize)	return 0;
	if (r == mSize - 1 && c == mSize - 1)	return 1;

	int& ret = cache[r][c];
	if (ret != -1) return ret; //���� cache[r][c]�� ��������?
	
	int jumpSize = map[r][c];
	return ret = jump(r + jumpSize, c) || jump(r, c + jumpSize);
}
int main() {
	int tc = 0;
	cin >> tc;

	while (tc--) {
		//�ʱ�ȭ
		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 102; j++) {
				map[i][j] = 0;
				cache[i][j] = -1;
			}
		}
		mSize = 0;
		cin >> mSize;

		for (int i = 0; i < mSize; i++) {
			for (int j = 0; j < mSize; j++) {
				cin >> map[i][j];
				cache[i][j] = -1;
			}
		}

		//������
		int res = jump(0, 0);
		if (res == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
	}
}