#include <iostream>
#include <algorithm>

using namespace std;

int cache[1024];
int hNum = 0;
int r[1024], g[1024], b[1024];

//r 0/ g 1/ b 2
int sol(int house, int cur, int res) {

	if (house == hNum) {
		return res;
	}
	if (cur == 0) {
		res += r[house];
		house++;
		return min(sol(house, 1, res), sol(house, 2, res));
	}
	else if (cur == 1) {
		res += g[house];
		house++;
		return min(sol(house, 0, res), sol(house, 2, res));
	}
	else if (cur == 2){
		res += b[house];
		house++;
		return min(sol(house, 0, res), sol(house, 1, res));
	}

	return res;
}
int main() {
	
	cin >> hNum;



	for (int i = 0; i < hNum; i++) {
		cin >> r[i] >> g[i] >> b[i];
	}
	int minRes = -1;
	
	
	cout << min(min(sol(0,0,0), sol(0,1,0)), sol(0,2,0)) << endl;
	return 0;
}