#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

vector<pair<string, int> > strArr;
vector<string> sameArr[1000];
vector<string> ans[1000];

int main() {
	int tc = 0, sameTc = 0;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		string t1;
		int t2;
		scanf("\n%s,%d", &t1, &t2);
		strArr.push_back(make_pair(t1, t2));
	}
	cin >> sameTc;
	for (int i = 0; i < sameTc; i++) {
		string t1, t2;
		scanf("\n%s,%s", &t1, &t2);

		for (int j = 0; j < 1000; j++) {
			int s = sameArr[j].size();
			for (int k = 0; k < s; k++) {
				if (sameArr[i].at(k) == t1) {
					sameArr[i].push_back(t1);
				}
				else {
					sameArr[i].push_back(t1);
					break;
				}
			}
		}
		for (int j = 0; j < 1000; j++) {
			int s = sameArr[j].size();
			for (int k = 0; k < s; k++) {
				if (sameArr[i].at(k) == t2) {
					sameArr[i].push_back(t2);
				}
				else {
					sameArr[i].push_back(t2);
					break;
				}
			}
		}
	}

	return 0;
}