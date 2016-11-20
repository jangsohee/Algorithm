#include <iostream>
#include <cmath>

using namespace std;

pair<pair<int, int>, pair<int, int> > pos[4];

int main() {
	
	int all = 0;
	int chk[102][102];

	for (int i = 0; i < 4; i++) {
		int x = 0, y = 0, x2 = 0, y2 = 0;
		cin >> x >> y >> x2 >> y2;
		pos[i] = make_pair(make_pair(x, y), make_pair(x2, y2));
		all += abs(x - x2) * abs(y - y2);
	}
	
	for (int i = 0; i < 4; i++) {
		int x = pos[i].first.first;
		int y = pos[i].first.second;
		int x2 = pos[i].second.first;
		int y2 = pos[i].second.second;

		for (int j = 0; j < 4; j++) {
			if (i == j) continue;

			int cmpx = pos[j].first.first;
			int cmpy = pos[j].first.second;
			int cmpx2 = pos[j].second.first;
			int cmpy2 = pos[j].second.second;

			if (x <= cmpx && cmpx <= x2) {
				int temp = abs(x2 - cmpx) * abs(y2 - cmpy);
				all -= temp;
			}
		}
	}

	cout << all << endl;

	return 0;
}
