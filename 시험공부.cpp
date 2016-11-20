#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[200002];
int main() {

	//int argc, char** argv ----------------------------------------------------------------1
	//setbuf(stdout, NULL); ----------------------------------------------------------------2

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr, arr + n);
		int res = 0;
		for (int i = 1; i <= k; i++) {
			res += arr[n - i];
		}
		printf("Case #%d\n", test_case);
		cout << res << endl;
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}