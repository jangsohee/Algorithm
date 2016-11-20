#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int inputs[22];
int res[22];
int main() {
	int n = 0, k = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d%*c", &inputs[i]);
	}

	for (int j = 0; j < k; j++) {
		for (int i = 0; i < n-j; i++) {
			res[i] = inputs[i + 1] - inputs[i];
		}
		memset(inputs, 0, sizeof(inputs));
		for (int i = 0; i < n-j; i++) {
			inputs[i] = res[i];
		}
	}
	
	if (n == 0) {
		cout << 0;
	}
	else if (k == 0) {
		for (int i = 0; i < n; i++) {
			printf("%d", inputs[i]);
			if (i != (n - k - 1)) printf(",");
		}
	}
	else {
		for (int i = 0; i < n-k; i++) {
			printf("%d", res[i]);
			if (i != (n - k - 1)) printf(",");
		}
	}
	
	printf("\n");

	return 0;
}