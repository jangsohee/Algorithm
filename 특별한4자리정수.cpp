#include <iostream>
#include <cstdio>

using namespace std;

int N[10] = { 10, 12, 16 };
int main() {
	
	int temp = 2992;
	while (temp < 10000) {
		bool flag = true;

		int res = 0;
		for (int i = 0; i < 3; i++) {
			int val = temp;
			int valRe = 0;
			while (val/N[i] != 0) {
				valRe += (val % N[i]);
				val = val / N[i];				
			}
			valRe += val;

			if (res == 0) res = valRe;
			else if (res != valRe) {
				flag = false;
				break;
			}
		}
		if(flag) cout << temp << endl;
		temp++;
	}
	return 0;
}