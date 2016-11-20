#include <iostream>

using namespace std;
 
long long color(string str, bool val) {
	if (str == "black") {
		if (val == true) {
			return 0;
		}
		return 1;
	}
	else if (str == "brown") {
		if (val == true) {
			return 1;
		}
		return 10;
	}
	else if (str == "red") {
		if (val == true) {
			return 2;
		}
		return 100;
	}
	else if (str == "orange") {
		if (val == true) {
			return 3;
		}
		return 1000;
	}
	else if (str == "yellow") {
		if (val == true) {
			return 4;
		}
		return 10000;
	}
	else if (str == "green") {
		if (val == true) {
			return 5;
		}
		return 100000;
	}
	else if (str == "blue") {
		if (val == true) {
			return 6;
		}
		return 1000000;
	}
	else if (str == "violet") {
		if (val == true) {
			return 7;
		}
		return 10000000;
	}
	else if (str == "grey") {
		if (val == true) {
			return 8;
		}
		return 100000000;
	}
	else if (str == "white") {
		if (val == true) {
			return 9;
		}
		return 1000000000;
	}
}
int main() {
	int cnt = 3;
	long long res = 0;
	while (cnt--) {
		char str[7] = "";
		cin >> str;
		if (cnt == 2) {
			res = color(str, true);
			res = res * 10;
		}
		else if (cnt == 1) {
			res += color(str, true);
		}
		else {
			res *= color(str, false);
		}
	}
	cout << res << endl;

	return 0;
}