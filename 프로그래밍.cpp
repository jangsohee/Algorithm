#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, num[300001];

int main() {

	//int argc, char** argv ----------------------------------------------------------------1
	//setbuf(stdout, NULL); ----------------------------------------------------------------2

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		sort(num, num + n);
		int cnt = 0;
		//max°ª Ã£±â
		int maxNum = 0;
		for (int i = 0; i < n; i++) {
			if (num[i] + n - i > maxNum) maxNum = num[i] + n - i;
		}
		for (int i = 0; i < n; i++) {
			if (num[i] + n >= maxNum) cnt++;
		}
		printf("Case #%d\n", test_case);
		cout << cnt << endl;
		n = 0;
		memset(num, 0, sizeof(num));
	}

	return 0;
}