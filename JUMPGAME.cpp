#include <iostream>

using namespace std;

int cache[102][102];
int map[102][102];
int mSize;

int jump(int r, int c) {
	if (r >= mSize || c >= mSize)	return 0;
	if (r == mSize - 1 && c == mSize - 1)	return 1;

	int& ret = cache[r][c];
	if (ret != -1) return ret; //리턴 cache[r][c]와 차이점은?
	
	int jumpSize = map[r][c];
	return ret = jump(r + jumpSize, c) || jump(r, c + jumpSize);
}
int main() {
	int tc = 0;
	cin >> tc;

	while (tc--) {
		//초기화
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

		//결과출력
		int res = jump(0, 0);
		if (res == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
	}
}