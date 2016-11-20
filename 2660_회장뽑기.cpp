#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int pp[100][100];
int res[100];
int visited[100];
int num = 0;
stack<int> sta;
int resultNum = 999;
void dfs(int cur, int step) {
	if (cur == num)	{
		if (resultNum > step) resultNum = step;
		return;
	}
	visited[cur] = 1;
	 
	for (int i = 1; i <= num; i++) {
		if (pp[cur][i] == 1 && visited[i] != 1) {
			pp[cur][i] = pp[i][cur] = 1;
			dfs(i, step+1);
		}
	}
}
int main() {
	
	cin >> num;

	int t1 = 0, t2 = 0;
	cin >> t1 >> t2;
	while (t1 != -1 &&  t2 != -1) {
		pp[t1][t2] = pp[t2][t1] = 1;
		cin >> t1 >> t2;
	}
	for (int i = 1; i <= num; i++) {
		dfs(i, 0);
		res[i] = resultNum;
		resultNum = 999;
	}

	sort(res, res + num);
	
	for (int i = 1; i <= num; i++) {
		cout << res[i] << endl;
	}
	
	
	return 0;
}