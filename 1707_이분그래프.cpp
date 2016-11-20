#include <cstdio>
#include <vector>

using namespace std;

vector<int> v[20002];
int color[20002];
int vNum = 0, eNum = 0;

void init() {
	for (int i = 0; i < 20002; i++) {
		v[i].clear();
		color[i] = 0;
		vNum = eNum = 0;
	}
}
void dfs(int n, int c) {
	color[n] = c;
	
	for (int i = 0; i < v[n].size(); i++) {
		int next = v[n].at(i);
		if (color[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}
int main() {
	int tc = 0;
	scanf("%d", &tc);
	while (tc--) {
		init();

		scanf("%d %d", &vNum, &eNum);
		for (int i = 0; i < eNum; i++) {
			int n1 = 0, n2 = 0;
			scanf("%d %d", &n1, &n2);
			v[n1].push_back(n2);
			v[n2].push_back(n1);
		}

		for (int i = 1; i <= vNum; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}

		bool res = true;
		for (int i = 1; i <= vNum; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (color[i] == color[v[i].at(j)]) {
					res = false;
				}
			}
		}

		printf("%s\n", res ? "YES" : "NO");

	}
	return 0;
}