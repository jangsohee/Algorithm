#include <cstdio>
#include <iostream>
using namespace std;

int main() {

	//int argc, char** argv ----------------------------------------------------------------1
	//setbuf(stdout, NULL); ----------------------------------------------------------------2

	int TC;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		unsigned int res = 0;
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			unsigned int temp = 0;
			scanf("%d", &temp);
			res ^= temp;
		}
		printf("Case #%d\n", test_case);
		cout << res << endl;
	}

	return 0;
}