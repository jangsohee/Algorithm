#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

string chk(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			cnt += 1;
		}
		else {
			cnt -= 1;
		}

		if (cnt < 0) {
			return "NO";
		}
	}

	if (cnt == 0) {
		return "YES";
	}
	return "NO";
}

int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << chk(s) << '\n';
	}
	return 0;
}
//int main() {
//	int tc;
//	cin >> tc;
//
//	while (tc--) {
//		stack<char> sta;
//		char str[52];
//		bool flag = true;
//		cin >> str;
//
//		int cnt = 0;
//		int leng = strlen(str);
//		for (int i = 0; i < leng; i++) {
//			if (str[i] == '(') {
//				sta.push('(');
//			}
//			else{
//				if (sta.empty()) {
//					flag = false;
//				}
//				else {
//					sta.pop();
//				}
//			}
//		}
//
//		if (flag && sta.empty()) cout << "YES" << '\n';
//		else cout << "NO" << '\n';
//	}
//	return 0;
//}