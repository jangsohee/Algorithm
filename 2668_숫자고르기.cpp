#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int mSize;
int map[102][102];
int res[102], sArr[102];
int visit[102];
int cNum, same, cnt;

int idx = 0;
int tempArr[102];

bool chk(int cur) {
	bool flag = true;
	for (int i = 0; i < cNum; i++) {
		if (res[i] == cur) flag = false;
	}
	
	return flag;
}
void cycle(int start, int cur) {
	if (start == cur && visit[cur] == 1 && chk(cur)) {
		
		for (int i = 1; i <= mSize; i++) {
			if (visit[i] == 1 && chk(i)) {
				tempArr[idx++] = i;
			}
		}
		for (int i = 0; i < idx; i++) {
			res[cNum++] = tempArr[i];
		}
		return;
	}

	for (int i = 1; i <= mSize; i++) {
		if (map[cur][i] == 1 && visit[cur] == 0) {
			visit[cur] = 1;
			cycle(start, i);
		}
	}
 
}
int main() {
	cin >> mSize;
	for (int i = 1; i <= mSize; i++) {
		int temp = 0;
		cin >> temp;
		map[i][temp] = 1;
	}

	for (int i = 1; i <= mSize; i++) {
		if (map[i][i] == 1) {
			map[i][i] = 0;
			sArr[same++] = i;
		}
		else {
			cycle(i, i);
			idx = 0;
			memset(tempArr, 0, sizeof(tempArr));
			memset(visit, 0, sizeof(visit));
		}
	}

	for (int i = 0; i < same; i++) {
		res[cNum++] = sArr[i];
	}
	sort(res, res + cNum);
	
	cout << cNum << '\n';
	for (int i = 0; i < cNum; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}